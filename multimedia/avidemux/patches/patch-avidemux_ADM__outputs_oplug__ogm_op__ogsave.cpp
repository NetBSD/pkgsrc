$NetBSD: patch-avidemux_ADM__outputs_oplug__ogm_op__ogsave.cpp,v 1.1 2020/01/02 19:47:04 rhialto Exp $

gcc7: error: call of overloaded 'abs(__uint32_t)' is ambiguous
so make the values signed so that a difference can properly be determined.

--- avidemux/ADM_outputs/oplug_ogm/op_ogsave.cpp.orig	2008-09-20 18:04:35.000000000 +0000
+++ avidemux/ADM_outputs/oplug_ogm/op_ogsave.cpp
@@ -163,7 +163,7 @@ uint8_t error=0;
 			}
 		}
 
-                if(abs(j-_togo)<3 && error) error=0; // might be caused by late B frame
+                if(abs((int64_t)j-(int64_t)_togo)<3 && error) error=0; // might be caused by late B frame
 		delete encoding_gui;
 		encoding_gui=NULL;
 		//________________ Flush______________________
