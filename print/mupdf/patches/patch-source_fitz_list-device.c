$NetBSD: patch-source_fitz_list-device.c,v 1.1 2019/07/06 11:27:48 leot Exp $

Backport commits ed19bc806809ad10c4ddce515d375581b86ede85 and
aaf794439e40a2ef544f15b50c20e657414dec7a to address CVE-2019-13290.

Commit ed19bc806809ad10c4ddce515d375581b86ede85:
> Bug 701118: Handle appending large display list nodes.
> 
> The size of the begin layer node depends on the size of the layer
> name. That name may be a string from the page's property resources,
> and is only bounded by memory when parsed by lex_string(). So the
> append_list_node() logic cannot simply double the size of the
> display list and hope that the node fits, since the node may be
> of arbitrary size.
> 
> Now append_list_node() would repeatedly double the size of the
> display list until the node fits, or malloc() runs out of memory.

Commit aaf794439e40a2ef544f15b50c20e657414dec7a:
> Bug 701118: Limit size of begin layer nodes in display list.
> 
> The size of the begin layer node depends on the size of the layer
> name. That name may be a string from the page's property resources,
> and is only bounded by memory when parsed by lex_string(). The
> layer name may cause a display node to be larger than the maximum
> size allowed. This condition is now checked for.

--- source/fitz/list-device.c.orig
+++ source/fitz/list-device.c
@@ -462,6 +462,9 @@ fz_append_display_node(
 	}
 	if (private_data != NULL)
 	{
+		int max = SIZE_IN_NODES(MAX_NODE_SIZE) - size;
+		if (SIZE_IN_NODES(private_data_len) > max)
+			fz_throw(ctx, FZ_ERROR_GENERIC, "Private data too large to pack into display list node");
 		private_off = size;
 		size += SIZE_IN_NODES(private_data_len);
 	}
@@ -466,7 +466,7 @@ fz_append_display_node(
 		size += SIZE_IN_NODES(private_data_len);
 	}
 
-	if (list->len + size > list->max)
+	while (list->len + size > list->max)
 	{
 		int newsize = list->max * 2;
 		fz_display_node *old = list->list;
