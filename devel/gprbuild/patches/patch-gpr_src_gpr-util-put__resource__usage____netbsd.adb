$NetBSD: patch-gpr_src_gpr-util-put__resource__usage____netbsd.adb,v 1.1 2024/03/12 17:50:13 wiz Exp $

Fix warning at link stage on NetBSD, it is a modified gpr/src/gpr-util-put_resource_usage__unix.adb file

--- /dev/null	2024-03-11 16:30:59.689872070 +0200
+++ gpr/src/gpr-util-put_resource_usage__netbsd.adb	2024-03-11 16:30:59.725273095 +0200
@@ -0,0 +1,120 @@
+------------------------------------------------------------------------------
+--                                                                          --
+--                           GPR PROJECT MANAGER                            --
+--                                                                          --
+--                     Copyright (C) 2022-2023, AdaCore                     --
+--                                                                          --
+-- This library is free software;  you can redistribute it and/or modify it --
+-- under terms of the  GNU General Public License  as published by the Free --
+-- Software  Foundation;  either version 3,  or (at your  option) any later --
+-- version. This library is distributed in the hope that it will be useful, --
+-- but WITHOUT ANY WARRANTY;  without even the implied warranty of MERCHAN- --
+-- TABILITY or FITNESS FOR A PARTICULAR PURPOSE.                            --
+--                                                                          --
+-- As a special exception under Section 7 of GPL version 3, you are granted --
+-- additional permissions described in the GCC Runtime Library Exception,   --
+-- version 3.1, as published by the Free Software Foundation.               --
+--                                                                          --
+-- You should have received a copy of the GNU General Public License and    --
+-- a copy of the GCC Runtime Library Exception along with this program;     --
+-- see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see    --
+-- <http://www.gnu.org/licenses/>.                                          --
+--                                                                          --
+------------------------------------------------------------------------------
+
+pragma Warnings (Off, "is an internal GNAT unit");
+with GNAT.Sockets.Thin_Common;
+pragma Warnings (On, "is an internal GNAT unit");
+
+separate (GPR.Util)
+procedure Put_Resource_Usage (Filename : String) is
+   package STC renames GNAT.Sockets.Thin_Common;
+
+   type Rusage is record
+      ru_utime    : STC.Timeval;  -- user time used
+      ru_stime    : STC.Timeval;  -- system time used
+      ru_maxrss   : Long_Integer; -- maximum resident set size
+      ru_ixrss    : Long_Integer; -- integral shared memory size
+      ru_idrss    : Long_Integer; -- integral unshared data size
+      ru_isrss    : Long_Integer; -- integral unshared stack size
+      ru_minflt   : Long_Integer; -- page reclaims
+      ru_majflt   : Long_Integer; -- page faults
+      ru_nswap    : Long_Integer; -- swaps
+      ru_inblock  : Long_Integer; -- block input operations
+      ru_oublock  : Long_Integer; -- block output operations
+      ru_msgsnd   : Long_Integer; -- messages sent
+      ru_msgrcv   : Long_Integer; -- messages received
+      ru_nsignals : Long_Integer; -- signals received
+      ru_nvcsw    : Long_Integer; -- voluntary context switches
+      ru_nivcsw   : Long_Integer; -- involuntary context switches
+   end record with Convention => C;
+
+   Log : File_Type;
+
+   RUSAGE_SELF     : constant := 0;
+   RUSAGE_CHILDREN : constant := -1;
+   RUSAGE_THREAD   : constant := 1;
+
+   procedure Print (Who : Integer);
+
+   -----------
+   -- Print --
+   -----------
+
+   procedure Print (Who : Integer) is
+      Usage : Rusage;
+      Longs : array (1 .. 14) of Long_Integer
+        with Import, Convention => C, Address => Usage.ru_maxrss'Address;
+
+      procedure Print (This : STC.Timeval);
+
+      function Getrusage (Who : Integer; usage : out Rusage) return Integer
+        with Import, Convention => C, External_Name => "__netbsd_getrusage";
+
+      -----------
+      -- Print --
+      -----------
+
+      procedure Print (This : STC.Timeval) is
+
+         function No_1st_Space (S : String) return String is
+           (if S /= "" and then S (S'First) = ' '
+            then S (S'First + 1 .. S'Last) else S);
+
+         Uimg : constant String := No_1st_Space (This.Tv_Usec'Img);
+      begin
+         Put (Log, This.Tv_Sec'Img);
+         Put (Log, '.');
+         if Uimg'Length < 6 then
+            Put (Log, (1 .. 6 - Uimg'Length => '0'));
+         end if;
+         Put (Log, Uimg);
+      end Print;
+
+   begin
+      if Getrusage (Who, Usage) /= 0 then
+         Put_Line (Log, "error: " & GNAT.OS_Lib.Errno_Message);
+         return;
+      end if;
+
+      Print (Usage.ru_utime);
+      Print (Usage.ru_stime);
+
+      for L of Longs loop
+         Put (Log, L'Img);
+      end loop;
+
+      New_Line (Log);
+
+      pragma Assert (Longs (Longs'Last)'Address = Usage.ru_nivcsw'Address);
+   end Print;
+
+begin
+   Create (Log, Out_File, Filename);
+
+   Print (RUSAGE_THREAD);
+   Print (RUSAGE_SELF);
+   Print (RUSAGE_CHILDREN);
+
+   Close (Log);
+end Put_Resource_Usage;
