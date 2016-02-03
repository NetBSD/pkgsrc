$NetBSD: patch-pcbnew_legacy_plugin.cpp,v 1.2 2016/02/03 19:34:34 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/legacy_plugin.cpp.orig	2015-12-11 18:15:36.000000000 +0100
+++ pcbnew/legacy_plugin.cpp	2015-12-11 18:17:49.000000000 +0100
@@ -2327,7 +2327,7 @@
 #endif
 
         int         makeType;
-        time_t      timeStamp;
+        u_long      timeStamp;
         LAYER_NUM   layer_num;
         int         type, net_code, flags_int;
 
@@ -2810,7 +2810,7 @@
         else if( TESTLINE( "Ge" ) )
         {
             LAYER_NUM layer_num;
-            time_t  timestamp;
+            u_long  timestamp;
             int     shape;
             int     ilayer;
 
@@ -3808,7 +3808,7 @@
                     fmtDEG( orient ).c_str(),
                     me->GetLayer(),
                     me->GetLastEditTime(),
-                    me->GetTimeStamp(),
+                    (u_long)me->GetTimeStamp(),
                     statusTxt );
 
     fprintf( m_fp, "Li %s\n", me->GetFPID().GetFootprintName().c_str() );
@@ -3823,7 +3823,7 @@
         fprintf( m_fp, "Kw %s\n", TO_UTF8( me->GetKeywords() ) );
     }
 
-    fprintf( m_fp, "Sc %lX\n", me->GetTimeStamp() );
+    fprintf( m_fp, "Sc %lX\n", (u_long)me->GetTimeStamp() );
     fprintf( m_fp, "AR %s\n", TO_UTF8( me->GetPath() ) );
     fprintf( m_fp, "Op %X %X 0\n", me->GetPlacementCost90(), me->GetPlacementCost180() );
 
@@ -3904,7 +3904,7 @@
              fmtBIUPoint( me->GetPosition() ).c_str(),
              fmtBIU( me->GetSize() ).c_str(),
              fmtBIU( me->GetWidth() ).c_str(),
-             me->GetTimeStamp()
+             (u_long)me->GetTimeStamp()
              );
 
     fprintf( m_fp, "$EndPCB_TARGET\n" );
@@ -3930,7 +3930,7 @@
                  me->GetLayer(),
                  me->GetType(),
                  fmtDEG( me->GetAngle() ).c_str(),
-                 me->GetTimeStamp(),
+                 (u_long)me->GetTimeStamp(),
                  me->GetStatus()
                  );
     }
@@ -3940,7 +3940,7 @@
                  me->GetLayer(),
                  me->GetType(),
                  fmtDEG( me->GetAngle() ).c_str(),
-                 me->GetTimeStamp(),
+                 (u_long)me->GetTimeStamp(),
                  me->GetStatus(),
                  fmtBIUPoint( me->GetBezControl1() ).c_str(),
                  fmtBIUPoint( me->GetBezControl2() ).c_str()
@@ -3975,7 +3975,7 @@
 
     fprintf(m_fp, "De %d %d %d %lX %X\n",
             me->GetLayer(), type, m_mapping->Translate( me->GetNetCode() ),
-            me->GetTimeStamp(), me->GetStatus() );
+            (u_long)me->GetTimeStamp(), me->GetStatus() );
 }
 
 
@@ -3987,7 +3987,7 @@
     // For keepout zones, net code and net name are irrelevant, so we store a dummy value
     // just for ZONE_CONTAINER compatibility
     fprintf( m_fp,  "ZInfo %lX %d %s\n",
-                    me->GetTimeStamp(),
+                    (u_long)me->GetTimeStamp(),
                     me->GetIsKeepout() ? 0 : m_mapping->Translate( me->GetNetCode() ),
                     EscapedUTF8( me->GetIsKeepout() ? wxT("") : me->GetNetname() ).c_str() );
 
@@ -4105,7 +4105,7 @@
     // this old keyword is used here for compatibility
     fprintf( m_fp, "$COTATION\n" );
 
-    fprintf( m_fp, "Ge %d %d %lX\n", me->GetShape(), me->GetLayer(), me->GetTimeStamp() );
+    fprintf( m_fp, "Ge %d %d %lX\n", me->GetShape(), me->GetLayer(), (u_long)me->GetTimeStamp() );
 
     fprintf( m_fp, "Va %s\n", fmtBIU( me->GetValue() ).c_str() );
 
@@ -4193,7 +4193,7 @@
     fprintf( m_fp,  "De %d %d %lX %s",
                     me->GetLayer(),
                     !me->IsMirrored(),
-                    me->GetTimeStamp(),
+                    (u_long)me->GetTimeStamp(),
                     me->IsItalic() ? "Italic" : "Normal" );
 
     if( me->GetHorizJustify() != GR_TEXT_HJUSTIFY_CENTER ||
