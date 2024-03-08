$NetBSD: patch-gcc_ada_libgnat_g-socthi____bsd.adb,v 1.1 2024/03/08 12:02:33 wiz Exp $

Create a g-socthi package that is common to all *BSD systems.

--- /dev/null	2023-12-10 09:29:26.388655944 +0200
+++ gcc/ada/libgnat/g-socthi__bsd.adb	2023-12-10 09:43:49.337413272 +0200
@@ -0,0 +1,356 @@
+------------------------------------------------------------------------------
+--                                                                          --
+--                         GNAT COMPILER COMPONENTS                         --
+--                                                                          --
+--                    G N A T . S O C K E T S . T H I N                     --
+--                                                                          --
+--                                 B o d y                                  --
+--                                                                          --
+--                     Copyright (C) 2001-2018, AdaCore                     --
+--                                                                          --
+-- GNAT is free software;  you can  redistribute it  and/or modify it under --
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
+-- GNAT was originally developed  by the GNAT team at  New York University. --
+-- Extensive contributions were provided by Ada Core Technologies Inc.      --
+--                                                                          --
+------------------------------------------------------------------------------
+
+--  This package provides a target dependent thin interface to the sockets
+--  layer for use by the GNAT.Sockets package (g-socket.ads). This package
+--  should not be directly with'ed by an applications program.
+
+--  This is the *BSD version which uses fcntl rather than ioctl
+--  The constant SCON.Thread_Blocking_IO is always true (for all platforms, not
+--  just *BSD), so this binding is significantly simpler than the standard
+--  one it replaces.
+
+with GNAT.OS_Lib; use GNAT.OS_Lib;
+
+with Interfaces.C; use Interfaces.C;
+
+package body GNAT.Sockets.Thin is
+
+   function Syscall_Accept
+     (S       : C.int;
+      Addr    : System.Address;
+      Addrlen : not null access C.int) return C.int;
+   pragma Import (C, Syscall_Accept, "accept");
+   --  The accept() function accepts a connection on a socket.  An incoming
+   --  connection is acknowledged and associated with an immediately created
+   --  socket.  The original socket is returned to the listening state.
+
+   function Syscall_Connect
+     (S       : C.int;
+      Name    : System.Address;
+      Namelen : C.int) return C.int;
+   pragma Import (C, Syscall_Connect, "connect");
+   --  The connect() system call initiates a connection on a socket.  If the
+   --  parameter S is of type SOCK_DGRAM then connect() permanently specifies
+   --  the peer to which datagrams are to be sent.  If S is type SOCK_STREAM
+   --  then connect() attempts to make a connection with another socket, which
+   --  is identified by the parameter Name.
+
+   function Syscall_Recv
+     (S     : C.int;
+      Msg   : System.Address;
+      Len   : C.size_t;
+      Flags : C.int) return C.int;
+   pragma Import (C, Syscall_Recv, "recv");
+   --  The recv() function receives a message from a socket.  The call can be
+   --  used on a connection mode socket or a bound, connectionless socket.  If
+   --  no messages are available at the socket, the recv() call waits for a
+   --  message to arrive unless the socket is non-blocking.  If a socket is
+   --  non-blocking, the call returns a -1 and ERRNO is set to EWOULDBLOCK.
+
+   function Syscall_Recvfrom
+     (S       : C.int;
+      Msg     : System.Address;
+      Len     : C.size_t;
+      Flags   : C.int;
+      From    : System.Address;
+      Fromlen : not null access C.int) return C.int;
+   pragma Import (C, Syscall_Recvfrom, "recvfrom");
+   --  The recvfrom() system call receives a message from a socket and captures
+   --  the address from which the data was sent.  It can be used to receive
+   --  data on an unconnected socket as well.  If no messages are available,
+   --  the call waits for a message to arrive on blocking sockets.  For
+   --  non-blocking sockets without messages, -1 is returned and ERRNO is set
+   --  to EAGAIN or EWOULDBLOCK.
+
+   function Syscall_Recvmsg
+     (S     : C.int;
+      Msg   : System.Address;
+      Flags : C.int) return System.CRTL.ssize_t;
+   pragma Import (C, Syscall_Recvmsg, "recvmsg");
+   --  The recvmsg call receives a message from a socket, and can be used to
+   --  receive data on an unconnected socket as well.  If no messages are
+   --  available, the call waits for a message to arrive on blocking sockets.
+   --  For non-blocking sockets without messages, -1 is returned and ERRNO is
+   --  set to EAGAIN or EWOULDBLOCK.
+
+   function Syscall_Sendmsg
+     (S     : C.int;
+      Msg   : System.Address;
+      Flags : C.int) return System.CRTL.ssize_t;
+   pragma Import (C, Syscall_Sendmsg, "sendmsg");
+   --  The sendmsg() function sends a message to a socket, and can be used with
+   --  unconnected sockets as well (the msg is ignored in this case).  The
+   --  function returns the number of bytes sent when successful, otherwise it
+   --  returns -1 and ERRNO is set (many possible values).
+
+   function Syscall_Sendto
+     (S     : C.int;
+      Msg   : System.Address;
+      Len   : C.size_t;
+      Flags : C.int;
+      To    : System.Address;
+      Tolen : C.int) return C.int;
+   pragma Import (C, Syscall_Sendto, "sendto");
+   --  The sendto() function only works for connected sockets and it initiates
+   --  the transmission of a message.  A successful call returns the numbers of
+   --  bytes sent, and a failure returns a -1 and ERRNO is set.
+
+   function Syscall_Socket
+     (Domain   : C.int;
+      Typ      : C.int;
+      Protocol : C.int) return C.int;
+   pragma Import (C, Syscall_Socket, "__gnat_socket");
+   --  The socket() function is used to create an unbound socket and returns a
+   --  file descriptor that can be used with other socket functions.  Upon
+   --  failure, a -1 is returned and ERRNO is set.
+
+   procedure Disable_SIGPIPE (S : C.int);
+   pragma Import (C, Disable_SIGPIPE, "__gnat_disable_sigpipe");
+
+   procedure Disable_All_SIGPIPEs;
+   pragma Import (C, Disable_All_SIGPIPEs, "__gnat_disable_all_sigpipes");
+   --  Sets the process to ignore all SIGPIPE signals on platforms that
+   --  don't support Disable_SIGPIPE for particular streams.
+
+   function C_Fcntl
+     (Fd  : C.int;
+      Cmd : C.int;
+      Val : C.int) return C.int;
+   pragma Import (C, C_Fcntl, "fcntl");
+   --  The ioctl of 64-bit DragonFlyBSD, OpenBSD, and NetBSD does not support
+   --  setting a socket in non-blocking mode.  fcntl must be used instead.
+
+   --------------
+   -- C_Accept --
+   --------------
+
+   function C_Accept
+     (S       : C.int;
+      Addr    : System.Address;
+      Addrlen : not null access C.int) return C.int
+   is
+      R : constant C.int := Syscall_Accept (S, Addr, Addrlen);
+   begin
+
+      Disable_SIGPIPE (R);
+      return R;
+   end C_Accept;
+
+   ---------------
+   -- C_Connect --
+   ---------------
+
+   function C_Connect
+     (S       : C.int;
+      Name    : System.Address;
+      Namelen : C.int) return C.int
+   is
+   begin
+      return Syscall_Connect (S, Name, Namelen);
+   end C_Connect;
+
+   ------------------
+   -- Socket_Ioctl --
+   ------------------
+
+   function Socket_Ioctl
+     (S   : C.int;
+      Req : SOSC.IOCTL_Req_T;
+      Arg : access C.int) return C.int
+   is
+   begin
+      if Req = SOSC.FIONBIO then
+         declare
+            use Interfaces;
+            flags    : constant Unsigned_32 :=
+                                Unsigned_32 (C_Fcntl (S, SOSC.F_GETFL, 0));
+            nonblock : constant Unsigned_32 := Unsigned_32 (SOSC.O_NDELAY);
+            enabled  : constant Boolean := Arg.all = 1;
+            newval   : C.int := C.int (flags);
+         begin
+            if enabled then
+               newval := C.int (flags or nonblock);
+            elsif (flags and nonblock) > 0 then
+               newval := C.int (flags - nonblock);
+            end if;
+            return C_Fcntl (Fd => S, Cmd => SOSC.F_SETFL, Val => newval);
+         end;
+      end if;
+
+      return C_Ioctl (S, Req, Arg);
+   end Socket_Ioctl;
+
+   ------------
+   -- C_Recv --
+   ------------
+
+   function C_Recv
+     (S     : C.int;
+      Msg   : System.Address;
+      Len   : C.size_t;
+      Flags : C.int) return C.int
+   is
+   begin
+      return Syscall_Recv (S, Msg, Len, Flags);
+   end C_Recv;
+
+   ----------------
+   -- C_Recvfrom --
+   ----------------
+
+   function C_Recvfrom
+     (S       : C.int;
+      Msg     : System.Address;
+      Len     : C.size_t;
+      Flags   : C.int;
+      From    : System.Address;
+      Fromlen : not null access C.int) return C.int
+   is
+   begin
+      return Syscall_Recvfrom (S, Msg, Len, Flags, From, Fromlen);
+   end C_Recvfrom;
+
+   ---------------
+   -- C_Recvmsg --
+   ---------------
+
+   function C_Recvmsg
+     (S     : C.int;
+      Msg   : System.Address;
+      Flags : C.int) return System.CRTL.ssize_t
+   is
+   begin
+      return Syscall_Recvmsg (S, Msg, Flags);
+   end C_Recvmsg;
+
+   ---------------
+   -- C_Sendmsg --
+   ---------------
+
+   function C_Sendmsg
+     (S     : C.int;
+      Msg   : System.Address;
+      Flags : C.int) return System.CRTL.ssize_t
+   is
+   begin
+      return Syscall_Sendmsg (S, Msg, Flags);
+   end C_Sendmsg;
+
+   --------------
+   -- C_Sendto --
+   --------------
+
+   function C_Sendto
+     (S     : C.int;
+      Msg   : System.Address;
+      Len   : C.size_t;
+      Flags : C.int;
+      To    : System.Address;
+      Tolen : C.int) return C.int
+   is
+   begin
+      return Syscall_Sendto (S, Msg, Len, Flags, To, Tolen);
+   end C_Sendto;
+
+   --------------
+   -- C_Socket --
+   --------------
+
+   function C_Socket
+     (Domain   : C.int;
+      Typ      : C.int;
+      Protocol : C.int) return C.int
+   is
+      R : constant C.int := Syscall_Socket (Domain, Typ, Protocol);
+   begin
+      Disable_SIGPIPE (R);
+      return R;
+   end C_Socket;
+
+   --------------
+   -- Finalize --
+   --------------
+
+   procedure Finalize is
+   begin
+      null;
+   end Finalize;
+
+   -------------------------
+   -- Host_Error_Messages --
+   -------------------------
+
+   package body Host_Error_Messages is separate;
+
+   ----------------
+   -- Initialize --
+   ----------------
+
+   procedure Initialize is
+   begin
+      Disable_All_SIGPIPEs;
+   end Initialize;
+
+   --------------------
+   -- Signalling_Fds --
+   --------------------
+
+   package body Signalling_Fds is
+
+      --  In this default implementation, we use a C version of these
+      --  subprograms provided by socket.c.
+
+      function C_Create (Fds : not null access Fd_Pair) return C.int;
+      function C_Read (Rsig : C.int) return C.int;
+      function C_Write (Wsig : C.int) return C.int;
+      procedure C_Close (Sig : C.int);
+
+      pragma Import (C, C_Create, "__gnat_create_signalling_fds");
+      pragma Import (C, C_Read,   "__gnat_read_signalling_fd");
+      pragma Import (C, C_Write,  "__gnat_write_signalling_fd");
+      pragma Import (C, C_Close,  "__gnat_close_signalling_fd");
+
+      function Create
+        (Fds : not null access Fd_Pair) return C.int renames C_Create;
+      function Read (Rsig : C.int) return C.int renames C_Read;
+      function Write (Wsig : C.int) return C.int renames C_Write;
+      procedure Close (Sig : C.int) renames C_Close;
+
+   end Signalling_Fds;
+
+   --------------------------
+   -- Socket_Error_Message --
+   --------------------------
+
+   function Socket_Error_Message (Errno : Integer) return String is separate;
+
+end GNAT.Sockets.Thin;
