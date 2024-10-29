$NetBSD: patch-lualib_rspamadm_dmarc__report.lua,v 1.1 2024/10/29 14:23:17 taca Exp $

Prevent DKIM verification problem with sendmail.

--- lualib/rspamadm/dmarc_report.lua.orig	2024-10-20 09:06:49.000000000 +0000
+++ lualib/rspamadm/dmarc_report.lua
@@ -391,7 +391,7 @@ local function rcpt_list(tbl, func)
     end
   end
 
-  return table.concat(res, ',')
+  return table.concat(res, ', ')
 end
 
 -- Synchronous smtp send function
