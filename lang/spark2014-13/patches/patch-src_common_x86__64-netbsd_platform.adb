$NetBSD: patch-src_common_x86__64-netbsd_platform.adb,v 1.1 2025/07/10 12:43:03 dkazankov Exp $

Add NetBSD support

--- /dev/null
+++ src/common/x86_64-netbsd/platform.adb
@@ -0,0 +1,37 @@
+------------------------------------------------------------------------------
+--                                                                          --
+--                            GNATPROVE COMPONENTS                          --
+--                                                                          --
+--                              P L A T F O R M                             --
+--                                                                          --
+--                                 B o d y                                  --
+--                                                                          --
+--                     Copyright (C) 2010-2023, AdaCore                     --
+--                                                                          --
+-- gnatprove is  free  software;  you can redistribute it and/or  modify it --
+-- under terms of the  GNU General Public License as published  by the Free --
+-- Software  Foundation;  either version 3,  or (at your option)  any later --
+-- version.  gnatprove is distributed  in the hope that  it will be useful, --
+-- but WITHOUT ANY WARRANTY; without even the implied warranty of  MERCHAN- --
+-- TABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public --
+-- License for  more details.  You should have  received  a copy of the GNU --
+-- General Public License  distributed with  gnatprove;  see file COPYING3. --
+-- If not,  go to  http://www.gnu.org/licenses  for a complete  copy of the --
+-- license.                                                                 --
+--                                                                          --
+-- gnatprove is maintained by AdaCore (http://www.adacore.com)              --
+--                                                                          --
+------------------------------------------------------------------------------
+
+package body Platform is
+
+   -------------------
+   -- Get_OS_Flavor --
+   -------------------
+
+   function Get_OS_Flavor return Host_Operating_System_Flavor is
+   begin
+      return X86_64_NetBSD;
+   end Get_OS_Flavor;
+
+end Platform;
