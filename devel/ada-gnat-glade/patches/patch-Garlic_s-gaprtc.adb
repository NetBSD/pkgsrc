$NetBSD: patch-Garlic_s-gaprtc.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e
Fix compilation warnings for GCC 13
https://github.com/reznikmm/garlic/commit/cd21e825da1a73bd853054ea19eae6a5437fb5e4


--- Garlic/s-gaprtc.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-gaprtc.adb
@@ -43,7 +43,6 @@
 with System.Garlic.Partitions;            use System.Garlic.Partitions;
 with System.Garlic.Physical_Location;     use System.Garlic.Physical_Location;
 with System.Garlic.Platform_Specific;
-with System.Garlic.Protocols;             use System.Garlic.Protocols;
 with System.Garlic.Soft_Links;
 with System.Garlic.Streams;               use System.Garlic.Streams;
 with System.Garlic.Table;
@@ -58,7 +57,7 @@
       Key     : Debug_Key := Private_Debug_Key)
      renames Print_Debug_Info;
 
-   use Ada.Streams, System.Garlic.Protocols, System.Garlic.Types;
+   use Ada.Streams, System.Garlic.Types;
 
    subtype Error_Type is Exceptions.Error_Type;
 
@@ -168,7 +167,6 @@
       Data  : access Stream_Element_Array;
       From  : Stream_Element_Count;
       Error : in out Error_Type);
-   pragma Inline (Send);
    pragma Export (Ada, Send, "GLADE_Physical_Send");
    --  Receive and send data. Receive loops as long as Data has not
    --  been filled and Send as long as everything has not
@@ -320,12 +318,11 @@
 
    function Do_Connect (Sock_Addr : Sock_Addr_Type) return Socket_Type is
       Peer : Socket_Type    := No_Socket;
-      Addr : Sock_Addr_Type := Sock_Addr;
 
    begin
       begin
          Create_Socket (Peer);
-         Connect_Socket (Peer, Addr);
+         Connect_Socket (Peer, Sock_Addr);
       exception when Socket_Error =>
          pragma Debug (D ("Cannot connect to " & Image (Sock_Addr)));
          if Peer /= No_Socket then
