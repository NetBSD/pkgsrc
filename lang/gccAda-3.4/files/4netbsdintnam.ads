------------------------------------------------------------------------------
--                                                                          --
--                GNU ADA RUN-TIME LIBRARY (GNARL) COMPONENTS               --
--                                                                          --
--                   A D A . I N T E R R U P T S . N A M E S                --
--                                                                          --
--                                  S p e c                                 --
--                                                                          --
--                                                                          --
--             Copyright (C) 1991-2002 Free Software Foundation, Inc.       --
--                                                                          --
-- GNARL is free software; you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 2,  or (at your option) any later ver- --
-- sion. GNARL is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License --
-- for  more details.  You should have  received  a copy of the GNU General --
-- Public License  distributed with GNARL; see file COPYING.  If not, write --
-- to  the Free Software Foundation,  59 Temple Place - Suite 330,  Boston, --
-- MA 02111-1307, USA.                                                      --
--                                                                          --
-- As a special exception,  if other files  instantiate  generics from this --
-- unit, or you link  this unit with other files  to produce an executable, --
-- this  unit  does not  by itself cause  the resulting  executable  to  be --
-- covered  by the  GNU  General  Public  License.  This exception does not --
-- however invalidate  any other reasons why  the executable file  might be --
-- covered by the  GNU Public License.                                      --
--                                                                          --
-- GNARL was developed by the GNARL team at Florida State University.       --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

--  This is a NetBSD version of this package.
--
with System.OS_Interface;
--  used for names of interrupts

package Ada.Interrupts.Names is

   --  Beware that the mapping of names to signals may be
   --  many-to-one.  There may be aliases.  Also, for all
   --  signal names that are not supported on the current system
   --  the value of the corresponding constant will be zero.

   Sighup    : constant Interrupt_ID := System.OS_Interface.sighup;
      --  hangup
   Sigint    : constant Interrupt_ID := System.OS_Interface.sigint;
      --  interrupt (rubout)
   Sigquit   : constant Interrupt_ID := System.OS_Interface.sigquit;
      --  quit (ASCD FS)
   Sigill    : constant Interrupt_ID := System.OS_Interface.sigill;
      --  illegal instruction (not reset)
   Sigtrap   : constant Interrupt_ID := System.OS_Interface.sigtrap;
      --  trace trap (not reset)
   Sigiot    : constant Interrupt_ID := System.OS_Interface.sigiot;
      --  IOT instruction
   SIGABRT   : constant Interrupt_ID := System.OS_Interface.SIGABRT;
      --  used by abort,--  replace SIGIOT in the  future
   Sigemt    : constant Interrupt_ID := System.OS_Interface.sigemt;
      --  EMT instruction
   Sigfpe    : constant Interrupt_ID := System.OS_Interface.sigfpe;
      --  floating point exception
   Sigkill   : constant Interrupt_ID := System.OS_Interface.sigkill;
      --  kill (cannot be caught or ignored)
   Sigbus    : constant Interrupt_ID := System.OS_Interface.sigbus;
      --  bus error
   Sigsegv   : constant Interrupt_ID := System.OS_Interface.sigsegv;
      --  segmentation violation
   Sigsys    : constant Interrupt_ID := System.OS_Interface.sigsys;
      --  bad argument to system call
   Sigpipe   : constant Interrupt_ID := System.OS_Interface.sigpipe;
      --  write on a pipe with--  no one to read it
   Sigalrm   : constant Interrupt_ID := System.OS_Interface.sigalrm;
      --  alarm clock
   Sigterm   : constant Interrupt_ID := System.OS_Interface.sigterm;
      --  software termination signal from kill
   Sigusr1   : constant Interrupt_ID := System.OS_Interface.sigusr1;
      --  user defined signal 1
   Sigusr2   : constant Interrupt_ID := System.OS_Interface.sigusr2;
      --  user defined signal 2
   Sigcld    : constant Interrupt_ID := System.OS_Interface.sigchld;
      --  child status change
   Sigchld   : constant Interrupt_ID := System.OS_Interface.sigchld;
      --  4.3BSD's/POSIX name for SIGCLD
   Sigwinch  : constant Interrupt_ID := System.OS_Interface.sigwinch;
      --  window size change
   Sigurg    : constant Interrupt_ID := System.OS_Interface.sigurg;
      --  urgent condition on IO channel
   Sigpoll   : constant Interrupt_ID := System.OS_Interface.sigio;
      --  pollable event occurred
   Sigio     : constant Interrupt_ID := System.OS_Interface.sigio;
      --  input/output possible,--  SIGPOLL alias (Solaris)
   Sigstop   : constant Interrupt_ID := System.OS_Interface.sigstop;
      --  stop (cannot be caught or ignored)
   Sigtstp   : constant Interrupt_ID := System.OS_Interface.sigtstp;
      --  user stop requested from tty
   Sigcont   : constant Interrupt_ID := System.OS_Interface.sigcont;
      --  stopped process has been continued
   Sigttin   : constant Interrupt_ID := System.OS_Interface.sigttin;
      --  background tty read attempted
   Sigttou   : constant Interrupt_ID := System.OS_Interface.sigttou;
      --  background tty write attempted
   Sigvtalrm : constant Interrupt_ID := System.OS_Interface.sigvtalrm;
      --  virtual timer expired
   Sigprof   : constant Interrupt_ID := System.OS_Interface.sigprof;
      --  profiling timer expired
   Sigxcpu   : constant Interrupt_ID := System.OS_Interface.sigxcpu;
      --  CPU time limit exceeded
   Sigxfsz   : constant Interrupt_ID := System.OS_Interface.sigxfsz;
      --  filesize limit exceeded
   Sigpwr    : constant Interrupt_ID := System.OS_Interface.sigpwr;
      --  power-fail restart
   Siginfo : constant Interrupt_ID := System.OS_Interface.siginfo;

end Ada.Interrupts.Names;
