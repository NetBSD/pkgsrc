$NetBSD: patch-gcc_ada_libgnarl_s-osinte____netbsd.adb,v 1.1 2024/03/08 12:02:33 wiz Exp $

Add NetBSD interface.

--- gcc/ada/libgnarl/s-osinte__netbsd.adb.orig	2021-10-08 11:29:30.470090202 +0200
+++ gcc/ada/libgnarl/s-osinte__netbsd.adb	2021-10-08 11:29:30.472274837 +0200
@@ -0,0 +1,140 @@
+------------------------------------------------------------------------------
+--                                                                          --
+--                  GNAT RUN-TIME LIBRARY (GNARL) COMPONENTS                --
+--                                                                          --
+--                   S Y S T E M . O S _ I N T E R F A C E                  --
+--                                                                          --
+--                                   B o d y                                --
+--                                                                          --
+--          Copyright (C) 1991-2015, Free Software Foundation, Inc.         --
+--                                                                          --
+-- GNARL is free software; you can  redistribute it  and/or modify it under --
+-- terms of the  GNU General Public License as published  by the Free Soft- --
+-- ware  Foundation;  either version 3,  or (at your option) any later ver- --
+-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
+-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
+-- or FITNESS FOR A PARTICULAR PURPOSE.                                     --
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
+-- GNARL was developed by the GNARL team at Florida State University. It is --
+-- now maintained by Ada Core Technologies Inc. in cooperation with Florida --
+-- State University (http://www.gnat.com).                                  --
+--                                                                          --
+------------------------------------------------------------------------------
+
+--  This is the NetBSD THREADS version of this package
+
+with Interfaces.C; use Interfaces.C;
+
+package body System.OS_Interface is
+
+   -----------
+   -- Errno --
+   -----------
+
+   function Errno return int is
+      type int_ptr is access all int;
+
+      function internal_errno return int_ptr;
+      pragma Import (C, internal_errno, "__errno");
+
+   begin
+      return (internal_errno.all);
+   end Errno;
+
+   --------------------
+   -- Get_Stack_Base --
+   --------------------
+
+   function Get_Stack_Base (thread : pthread_t) return Address is
+      pragma Unreferenced (thread);
+   begin
+      return Null_Address;
+   end Get_Stack_Base;
+
+   ------------------
+   -- pthread_init --
+   ------------------
+
+   procedure pthread_init is
+   begin
+      null;
+   end pthread_init;
+
+   -----------------------------------
+   -- pthread_mutexattr_setprotocol --
+   -----------------------------------
+
+   function pthread_mutexattr_setprotocol
+     (attr     : access pthread_mutexattr_t;
+      protocol : int) return int is
+      pragma Unreferenced (attr, protocol);
+   begin
+      return 0;
+   end pthread_mutexattr_setprotocol;
+
+   --------------------------------------
+   -- pthread_mutexattr_setprioceiling --
+   --------------------------------------
+
+   function pthread_mutexattr_setprioceiling
+     (attr     : access pthread_mutexattr_t;
+      prioceiling : int) return int is
+      pragma Unreferenced (attr, prioceiling);
+   begin
+      return 0;
+   end pthread_mutexattr_setprioceiling;
+
+   -----------------
+   -- To_Duration --
+   -----------------
+
+   function To_Duration (TS : timespec) return Duration is
+   begin
+      return Duration (TS.ts_sec) + Duration (TS.ts_nsec) / 10#1#E9;
+   end To_Duration;
+
+   ------------------------
+   -- To_Target_Priority --
+   ------------------------
+
+   function To_Target_Priority
+     (Prio : System.Any_Priority) return Interfaces.C.int
+   is
+   begin
+      return Interfaces.C.int (Prio);
+   end To_Target_Priority;
+
+   -----------------
+   -- To_Timespec --
+   -----------------
+
+   function To_Timespec (D : Duration) return timespec is
+      S : time_t;
+      F : Duration;
+
+   begin
+      S := time_t (Long_Long_Integer (D));
+      F := D - Duration (S);
+
+      --  If F has negative value due to a round-up, adjust for positive F
+      --  value.
+
+      if F < 0.0 then
+         S := S - 1;
+         F := F + 1.0;
+      end if;
+
+      return timespec'(ts_sec => S,
+                       ts_nsec => long (Long_Long_Integer (F * 10#1#E9)));
+   end To_Timespec;
+
+end System.OS_Interface;
