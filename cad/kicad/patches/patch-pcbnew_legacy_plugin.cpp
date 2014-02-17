$NetBSD: patch-pcbnew_legacy_plugin.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/legacy_plugin.cpp.orig	2014-02-14 21:55:49.000000000 +0100
+++ pcbnew/legacy_plugin.cpp	2014-02-15 16:53:33.000000000 +0100
@@ -1988,7 +1988,7 @@
 #endif
 
         int         makeType;
-        time_t      timeStamp;
+        u_long      timeStamp;
         int         layer, type, flags, net_code;
 
         // parse the 2nd line to determine the type of object
@@ -2435,7 +2435,7 @@
         else if( TESTLINE( "Ge" ) )
         {
             int     layer;
-            time_t  timestamp;
+            u_long  timestamp;
             int     shape;
 
             sscanf( line + SZ( "Ge" ), " %d %d %lX", &shape, &layer, &timestamp );
@@ -2447,7 +2447,7 @@
                 layer = LAST_NO_COPPER_LAYER;
 
             dim->SetLayer( layer );
-            dim->SetTimeStamp( timestamp );
+            dim->SetTimeStamp( (time_t)timestamp );
             dim->SetShape( shape );
         }
 
@@ -3398,8 +3398,8 @@
                     fmtBIUPoint( me->GetPosition() ).c_str(),    // m_Pos.x, m_Pos.y,
                     fmtDEG( orient ).c_str(),
                     me->GetLayer(),
-                    me->GetLastEditTime(),
-                    me->GetTimeStamp(),
+                    (u_long)me->GetLastEditTime(),
+                    (u_long)me->GetTimeStamp(),
                     statusTxt );
 
     fprintf( m_fp, "Li %s\n", TO_UTF8( me->GetLibRef() ) );
@@ -3414,7 +3414,7 @@
         fprintf( m_fp, "Kw %s\n", TO_UTF8( me->GetKeywords() ) );
     }
 
-    fprintf( m_fp, "Sc %lX\n", me->GetTimeStamp() );
+    fprintf( m_fp, "Sc %lX\n", (u_long)me->GetTimeStamp() );
     fprintf( m_fp, "AR %s\n", TO_UTF8( me->GetPath() ) );
     fprintf( m_fp, "Op %X %X 0\n", me->m_CntRot90, me->m_CntRot180 );
 
@@ -3543,7 +3543,7 @@
              fmtBIUPoint( me->GetPosition() ).c_str(),
              fmtBIU( me->GetSize() ).c_str(),
              fmtBIU( me->GetWidth() ).c_str(),
-             me->GetTimeStamp()
+             (u_long)me->GetTimeStamp()
              );
 
     fprintf( m_fp, "$EndPCB_TARGET\n" );
@@ -3569,7 +3569,7 @@
                  me->GetLayer(),
                  me->GetType(),
                  fmtDEG( me->GetAngle() ).c_str(),
-                 me->GetTimeStamp(),
+                 (u_long)me->GetTimeStamp(),
                  me->GetStatus()
                  );
     }
@@ -3579,7 +3579,7 @@
                  me->GetLayer(),
                  me->GetType(),
                  fmtDEG( me->GetAngle() ).c_str(),
-                 me->GetTimeStamp(),
+                 (u_long)me->GetTimeStamp(),
                  me->GetStatus(),
                  fmtBIUPoint( me->GetBezControl1() ).c_str(),
                  fmtBIUPoint( me->GetBezControl2() ).c_str()
@@ -3607,7 +3607,7 @@
 
     fprintf(m_fp, "De %d %d %d %lX %X\n",
             me->GetLayer(), type, me->GetNet(),
-            me->GetTimeStamp(), me->GetStatus() );
+            (u_long)me->GetTimeStamp(), me->GetStatus() );
 }
 
 
@@ -3619,7 +3619,7 @@
     // For keepout zones, net code and net name are irrelevant, so we store a dummy value
     // just for ZONE_CONTAINER compatibility
     fprintf( m_fp,  "ZInfo %lX %d %s\n",
-                    me->GetTimeStamp(),
+                    (u_long)me->GetTimeStamp(),
                     me->GetIsKeepout() ? 0 : me->GetNet(),
                     EscapedUTF8( me->GetIsKeepout() ? wxT("") : me->GetNetName() ).c_str() );
 
@@ -3737,7 +3737,7 @@
     // this old keyword is used here for compatibility
     fprintf( m_fp, "$COTATION\n" );
 
-    fprintf( m_fp, "Ge %d %d %lX\n", me->GetShape(), me->GetLayer(), me->GetTimeStamp() );
+    fprintf( m_fp, "Ge %d %d %lX\n", me->GetShape(), me->GetLayer(), (u_long)me->GetTimeStamp() );
 
     fprintf( m_fp, "Va %s\n", fmtBIU( me->m_Value ).c_str() );
 
@@ -3825,7 +3825,7 @@
     fprintf( m_fp,  "De %d %d %lX %s",
                     me->GetLayer(),
                     !me->IsMirrored(),
-                    me->GetTimeStamp(),
+                    (u_long)me->GetTimeStamp(),
                     me->IsItalic() ? "Italic" : "Normal" );
 
     if( me->GetHorizJustify() != GR_TEXT_HJUSTIFY_CENTER ||
