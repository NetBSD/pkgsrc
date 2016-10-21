$NetBSD: patch-src_interface_queue.cpp,v 1.1 2016/10/21 15:29:11 wiz Exp $

Upstream patch for an assert():
https://svn.filezilla-project.org/filezilla/FileZilla3/trunk/src/interface/queue.cpp?view=patch&r1=7884&r2=7883&pathrev=7884

--- src/interface/queue.cpp.orig	2016-05-19 07:57:30.000000000 +0000
+++ src/interface/queue.cpp
@@ -1049,12 +1049,20 @@ void CQueueViewBase::UpdateSelections_It
 			SetItemState(itemsToSelect.front(), wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
 			itemsToSelect.pop_front();
 		}
-		if (itemsToSelect.empty())
-			SetItemState(item, 0, wxLIST_STATE_SELECTED);
-		else if (itemsToSelect.front() == item)
+		if (itemsToSelect.front() == item) {
 			itemsToSelect.pop_front();
+		}
+		else {
+			SetItemState(item, 0, wxLIST_STATE_SELECTED);
+		}
 
 		itemsToSelect.push_back(item + count);
+		if (item + count < GetItemCount()) {
+			// On generic list controls, new items may be selected by default after
+			// increasing the item count: Internally it sometimes keeps track
+			// of only unselected items.
+			itemsToSelect.push_back(item + count);
+		}
 
 		item = GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
 	}
