------------------------------------------------------------------------------
--                                                                          --
--                GNU ADA RUN-TIME LIBRARY (GNARL) COMPONENTS               --
--                                                                          --
--                   S Y S T E M . O S _ I N T E R F A C E                  --
--                                                                          --
--                                  S p e c                                 --
--                                                                          --
--                                                                          --
--          Copyright (C) 1997-2001 Free Software Foundation, Inc.          --
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

--  This package includes all direct interfaces to OS services
--  that are needed by children of System.

--  PLEASE DO NOT add any with-clauses to this package
--  or remove the pragma Elaborate_Body.
--  It is designed to be a bottom-level (leaf) package.

with Interfaces.C;
package System.OS_Interface is
   pragma Preelaborate;

   pragma Linker_Options ("-lposix");
   pragma Linker_Options ("-lpthread");

   subtype int            is Interfaces.C.int;
   subtype short          is Interfaces.C.short;
   subtype long           is Interfaces.C.long;
   subtype unsigned       is Interfaces.C.unsigned;
   subtype unsigned_short is Interfaces.C.unsigned_short;
   subtype unsigned_long  is Interfaces.C.unsigned_long;
   subtype unsigned_char  is Interfaces.C.unsigned_char;
   subtype plain_char     is Interfaces.C.plain_char;
   subtype size_t         is Interfaces.C.size_t;

   type int32_t is range -2**31 .. (2**31)-1;
   for int32_t'Size use 32;

   -----------
   -- Errno --
   -----------

   function Errno return int;
   pragma Import (C, Errno, "__get_errno");

   EPERM   : constant := 1;  -- Operation not permitted
   ENOENT  : constant := 2;  -- No such file or directory
   ESRCH   : constant := 3;  -- No such process
   EINTR   : constant := 4;  -- Interrupted system call
   EIO     : constant := 5;  -- Input/output error
   ENXIO   : constant := 6;  -- Device not configured
   E2BIG   : constant := 7;  -- Argument list too long
   ENOEXEC : constant := 8;  -- Exec format error
   EBADF   : constant := 9;  -- Bad file descriptor
   ECHILD  : constant := 10; -- No child processes
   EDEADLK : constant := 11; -- Resource deadlock avoided
   ENOMEM          : constant := 12;     -- Cannot allocate memory
   EACCES          : constant := 13;     -- Permission denied
   EFAULT          : constant := 14;     -- Bad address
   ENOTBLK         : constant := 15;     -- Block device required
   EBUSY           : constant := 16;     -- Device busy
   EEXIST          : constant := 17;     -- File exists
   EXDEV           : constant := 18;     -- Cross-device link
   ENODEV          : constant := 19;
   ENOTDIR         : constant := 20;     -- Not a directory
   EISDIR          : constant := 21;     -- Is a directory
   EINVAL          : constant := 22;     -- Invalid argument
   ENFILE          : constant := 23;
   EMFILE          : constant := 24;     -- Too many open files
   ENOTTY          : constant := 25;
   ETXTBSY         : constant := 26;     -- Text file busy
   EFBIG           : constant := 27;     -- File too large
   ENOSPC          : constant := 28;     -- No space left on device
   ESPIPE          : constant := 29;     -- Illegal seek
   EROFS           : constant := 30;     -- Read-only file system
   EMLINK          : constant := 31;     -- Too many links
   EPIPE           : constant := 32;     -- Broken pipe
   EDOM            : constant := 33;
   ERANGE          : constant := 34;
   EAGAIN          : constant := 35;
   EWOULDBLOCK     : constant := EAGAIN; -- Operation would block
   EINPROGRESS     : constant := 36;     -- Operation now in progress
   EALREADY        : constant := 37;
   ENOTSOCK        : constant := 38;
   EDESTADDRREQ    : constant := 39;
   EMSGSIZE        : constant := 40;     -- Message too long
   EPROTOTYPE      : constant := 41;
   ENOPROTOOPT     : constant := 42;     -- Protocol not available
   EPROTONOSUPPORT : constant := 43;     -- Protocol not supported
   ESOCKTNOSUPPORT : constant := 44;     -- Socket type not supported
   EOPNOTSUPP      : constant := 45;     -- Operation not supported
   EPFNOSUPPORT    : constant := 46;
   EAFNOSUPPORT    : constant := 47;
   EADDRINUSE      : constant := 48;     -- Address already in use
   EADDRNOTAVAIL   : constant := 49;
   ENETDOWN        : constant := 50;     -- Network is down
   ENETUNREACH     : constant := 51;     -- Network is unreachable
   ENETRESET       : constant := 52;
   ECONNABORTED    : constant := 53;
   ECONNRESET      : constant := 54;     -- Connection reset by peer
   ENOBUFS         : constant := 55;     -- No buffer space available
   EISCONN         : constant := 56;
   ENOTCONN        : constant := 57;     -- Socket is not connected
   ESHUTDOWN       : constant := 58;
   ETOOMANYREFS    : constant := 59;
   ETIMEDOUT       : constant := 60;     -- Operation timed out
   ECONNREFUSED    : constant := 61;     -- Connection refused
   ELOOP           : constant := 62;
   ENAMETOOLONG    : constant := 63;     -- File name too long
   EHOSTDOWN       : constant := 64;     -- Host is down
   EHOSTUNREACH    : constant := 65;     -- No route to host
   ENOTEMPTY       : constant := 66;     -- Directory not empty
   EPROCLIM        : constant := 67;     -- Too many processes
   EUSERS          : constant := 68;     -- Too many users
   EDQUOT          : constant := 69;     -- Disc quota exceeded
   ESTALE          : constant := 70;     -- Stale NFS file handle
   EREMOTE         : constant := 71;
   EBADRPC         : constant := 72;     -- RPC struct is bad
   ERPCMISMATCH    : constant := 73;     -- RPC version wrong
   EPROGUNAVAIL    : constant := 74;     -- RPC prog. not avail
   EPROGMISMATCH   : constant := 75;     -- Program version wrong
   EPROCUNAVAIL    : constant := 76;     -- Bad procedure for program
   ENOLCK          : constant := 77;     -- No locks available
   ENOSYS          : constant := 78;     -- Function not implemented
   EFTYPE          : constant := 79;
   EAUTH           : constant := 80;     -- Authentication error
   ENEEDAUTH       : constant := 81;     -- Need authenticator
   EIDRM           : constant := 82;     -- Identifier removed
   ENOMSG          : constant := 83;     -- No message of desired type
   EOVERFLOW       : constant := 84;
   EILSEQ          : constant := 85;     -- Illegal byte sequence
   ENOTSUP         : constant := 86;     -- Not supported
   ECANCELED       : constant := 87;     -- Operation canceled
   EBADMSG         : constant := 88;     -- Bad or Corrupt message
   ENODATA         : constant := 89;     -- No message available
   ENOSR           : constant := 90;     -- No STREAM resources
   ENOSTR          : constant := 91;     -- Not a STREAM
   ETIME           : constant := 92;     -- STREAM ioctl timeout
   ELAST           : constant := 92;     -- Must equal largest errno

   -------------
   -- Signals --
   -------------
   Max_Interrupt : constant := 64;
   type Signal is new int range 0 .. Max_Interrupt;
   for Signal'Size use int'Size;

   sighup  : constant := 1; -- hangup
   sigint  : constant := 2; -- interrupt
   sigquit : constant := 3; -- quit
   sigill  : constant := 4; -- illegal instruction (not reset when caught)
   sigtrap : constant := 5; -- trace trap (not reset when caught)
   SIGABRT : constant := 6;       -- abort()
   sigiot  : constant := SIGABRT; -- compatibility
   sigemt  : constant := 7;       -- EMT instruction
   sigfpe  : constant := 8;       -- floating point exception
   sigkill : constant := 9; -- kill (cannot be caught or ignored)
   sigbus  : constant := 10;      -- bus error
   sigsegv : constant := 11;      -- segmentation violation
   sigsys  : constant := 12;      -- bad argument to system call
   sigpipe : constant := 13; -- write on a pipe with no one to read it
   sigalrm : constant := 14; -- alarm clock
   sigterm : constant := 15; -- software termination signal from kill
   sigurg  : constant := 16; -- urgent condition on IO channel
   sigstop : constant := 17; -- sendable stop signal not from tty
   sigtstp : constant := 18; -- stop signal from tty
   sigcont : constant := 19; -- continue a stopped process
   sigchld : constant := 20; -- to parent on child stop or exit
   sigttin : constant := 21; -- to readers pgrp upon background tty read
   sigttou : constant := 22; -- like TTIN for output if (tp->t_local&LTOSTOP)
   sigio     : constant := 23; -- input/output possible signal
   sigxcpu   : constant := 24; -- exceeded CPU time limit
   sigxfsz   : constant := 25; -- exceeded file size limit
   sigvtalrm : constant := 26; -- virtual time alarm
   sigprof   : constant := 27; -- profiling time alarm
   sigwinch  : constant := 28; -- window size changes
   siginfo   : constant := 29; -- information request
   sigusr1   : constant := 30; -- user defined signal 1
   sigusr2   : constant := 31; -- user defined signal 2
   sigpwr    : constant := 32; -- power fail/restart (not reset when caught)
   sigwaiting : constant := 0; -- process's lwps blocked (Solaris)
   sigcancel : constant := 0; --  thread cancellation signal (libthread)

   SIGADAABORT : constant := SIGABRT;

   type signal_set is array (Natural range <>) of Signal;

   Unmasked : constant signal_set := (sigkill, sigill, sigprof, sigtrap,
     sigpwr);

   --  Following signals should not be disturbed.
   --  See c-posix-signals.c in FLORIST
   Reserved : constant signal_set := (sigalrm, sigbus, sigill, sigsegv,
     sigfpe, SIGABRT, sigkill, sigstop);

   --  PTHREAD_SIGMASK(3)
   SIG_BLOCK : constant := 1;
   SIG_SETMASK : constant := 3;
   SIG_UNBLOCK : constant := 2;

   type sigset_t is private;
   type sigset_t_ptr is access all sigset_t;

   --  Binding to macros defined in <signal.h>
   function sigaddset (set : access sigset_t; sig : Signal) return int;
   pragma Import (C, sigaddset, "adasigaddset");

   function sigdelset (set : access sigset_t; sig : Signal) return int;
   pragma Import (C, sigdelset, "adasigdelset");

   function sigfillset (set : access sigset_t) return int;
   pragma Import (C, sigfillset, "adasigfillset");

   function sigismember (set : access sigset_t; sig : Signal) return int;
   pragma Import (C, sigismember, "adasigismember");

   function sigemptyset (set : access sigset_t) return int;
   pragma Import (C, sigemptyset, "adasigemptyset");

   type struct_sigaction is record
      sa_handler : System.Address;
      sa_mask : sigset_t;
      sa_flags : int;
   end record;
   pragma Convention (C, struct_sigaction);
   type struct_sigaction_ptr is access all struct_sigaction;

   SIG_DFL : constant := 0;
   SIG_IGN : constant := 1;

   function sigaction
     (sig  : Signal;
      act  : struct_sigaction_ptr;
      oact : struct_sigaction_ptr := null) return int;
   pragma Import (C, sigaction, "adasigaction");

   ----------
   -- Time --
   ----------

   type clockid_t is new int;
   CLOCK_REALTIME : constant := 0;

   type timespec is private;

   function To_Duration (
         TS : timespec)
     return Duration;
   pragma Inline (To_Duration);

   function To_Timespec (
         D : Duration)
     return timespec;
   pragma Inline (To_Timespec);

   type Struct_Timeval is private;

   function To_Duration (
         TV : Struct_Timeval)
     return Duration;
   pragma Inline (To_Duration);

   function To_Timeval (
         D : Duration)
     return Struct_Timeval;
   pragma Inline (To_Timeval);

   function Gettimeofday (
         Tv : access Struct_Timeval;
         Tz :        System.Address := System.Null_Address)
     return int;
   pragma Import (C, Gettimeofday, "gettimeofday");

   function clock_gettime
     (clock_id : clockid_t;
      tp       : access timespec) return int;
   pragma Import (C, clock_gettime, "clock_gettime");


   ---------
   -- LWP --
   ---------

   --  From <sys/types.h>
   type lwpid_t is new int32_t;

   function lwp_self return System.Address;
   pragma Import (C, lwp_self, "ada_lwp_self");


   -------------------------
   -- Priority Scheduling --
   -------------------------

   SCHED_FIFO  : constant := 1;
   SCHED_RR    : constant := 2;
   SCHED_TS    : constant := 3;
   SCHED_OTHER : constant := 3;
   SCHED_NP    : constant := 4;

   function sched_get_priority_min (Policy : int) return int;
   pragma Import (C, sched_get_priority_min, "sched_get_priority_min");

   function sched_get_priority_max (Policy : int) return int;
   pragma Import (C, sched_get_priority_max, "sched_get_priority_max");

   -------------
   -- Process --
   -------------

   type pid_t is private;

   function kill (pid : pid_t; sig : Signal) return int;
   pragma Import (C, kill, "kill");

   function getpid return pid_t;
   pragma Import (C, getpid, "getpid");

   -------------
   -- Threads --
   -------------

   type Thread_Body is access
     function (arg : System.Address) return System.Address;
   type pthread_t           is private;
   subtype Thread_Id        is pthread_t;

   type pthread_mutex_t     is limited private;
   type pthread_cond_t      is limited private;
   type pthread_attr_t      is limited private;
   type pthread_mutexattr_t is limited private;
   type pthread_condattr_t  is limited private;
   type pthread_key_t       is private;
   subtype cond_t is pthread_cond_t;

   PTHREAD_CREATE_DETACHED : constant := 1;

   ---------------------------------------
   -- Nonstandard Thread Initialization --
   ---------------------------------------

   procedure pthread_init;
   pragma Inline (pthread_init);
   --  This is a dummy procedure to share some GNULLI files

   -------------------------
   -- POSIX.1c  Section 3 --
   -------------------------

   function sigwait
     (set : access sigset_t;
      sig : access Signal) return int;
   pragma Import (C, sigwait, "adasigwait");

   function pthread_kill
     (thread : pthread_t;
      sig    : Signal) return int;
   pragma Import (C, pthread_kill, "pthread_kill");

   function pthread_sigmask
     (how  : int;
      set  : sigset_t_ptr;
      oset : sigset_t_ptr) return int;
   pragma Import (C, pthread_sigmask, "pthread_sigmask");

   --------------------------
   -- POSIX.1c  Section 11 --
   --------------------------

   function pthread_mutexattr_init
     (attr : access pthread_mutexattr_t) return int;
   pragma Import (C, pthread_mutexattr_init, "pthread_mutexattr_init");

   function pthread_mutexattr_destroy
     (attr : access pthread_mutexattr_t) return int;
   pragma Import (C, pthread_mutexattr_destroy, "pthread_mutexattr_destroy");

   function pthread_mutex_init
     (mutex : access pthread_mutex_t;
      attr  : access pthread_mutexattr_t) return int;
   pragma Import (C, pthread_mutex_init, "pthread_mutex_init");

   function pthread_mutex_destroy (mutex : access pthread_mutex_t) return int;
   pragma Import (C, pthread_mutex_destroy, "pthread_mutex_destroy");

   function pthread_mutex_lock (mutex : access pthread_mutex_t) return int;
   pragma Import (C, pthread_mutex_lock, "pthread_mutex_lock");

   function pthread_mutex_unlock (mutex : access pthread_mutex_t) return int;
   pragma Import (C, pthread_mutex_unlock, "pthread_mutex_unlock");

   function pthread_condattr_init
     (attr : access pthread_condattr_t) return int;
   pragma Import (C, pthread_condattr_init, "pthread_condattr_init");

   function pthread_condattr_destroy
     (attr : access pthread_condattr_t) return int;
   pragma Import (C, pthread_condattr_destroy, "pthread_condattr_destroy");

   function pthread_cond_init
     (cond : access pthread_cond_t;
      attr : access pthread_condattr_t) return int;
   pragma Import (C, pthread_cond_init, "pthread_cond_init");

   function pthread_cond_destroy (cond : access pthread_cond_t) return int;
   pragma Import (C, pthread_cond_destroy, "pthread_cond_destroy");

   function pthread_cond_signal (cond : access pthread_cond_t) return int;
   pragma Import (C, pthread_cond_signal, "pthread_cond_signal");

   function pthread_cond_wait
     (cond  : access pthread_cond_t;
      mutex : access pthread_mutex_t) return int;
   pragma Import (C, pthread_cond_wait, "pthread_cond_wait");

   function pthread_cond_timedwait
     (cond    : access pthread_cond_t;
      mutex   : access pthread_mutex_t;
      abstime : access timespec) return int;
   pragma Import (C, pthread_cond_timedwait, "pthread_cond_timedwait");

   --------------------------
   -- POSIX.1c  Section 13 --
   --------------------------

   PTHREAD_PRIO_NONE    : constant := 0;
   PTHREAD_PRIO_PROTECT : constant := 2;
   PTHREAD_PRIO_INHERIT : constant := 1;

   function pthread_mutexattr_setprotocol
     (attr     : access pthread_mutexattr_t;
      protocol : int) return int;
   pragma Import
     (C, pthread_mutexattr_setprotocol, "pthread_mutexattr_setprotocol");

   function pthread_mutexattr_setprioceiling
     (attr     : access pthread_mutexattr_t;
      prioceiling : int) return int;
   pragma Import
     (C, pthread_mutexattr_setprioceiling, "pthread_mutexattr_setprioceiling");

   type struct_sched_param is record
      sched_priority : int;
   end record;
   for struct_sched_param use record
      sched_priority at 0 range 0 .. 31;
   end record;
   pragma Convention (C, struct_sched_param);

   function pthread_setschedparam
     (thread : pthread_t;
      policy : int;
      param  : access struct_sched_param)
     return int;
   pragma Import (C, pthread_setschedparam, "pthread_setschedparam");

   function pthread_attr_setscope
     (attr            : access pthread_attr_t;
      contentionscope : int) return int;
   pragma Import (C, pthread_attr_setscope, "pthread_attr_setscope");

   function pthread_attr_setinheritsched
     (attr         : access pthread_attr_t;
      inheritsched : int) return int;
   pragma Import
     (C, pthread_attr_setinheritsched, "pthread_attr_setinheritsched");

   function pthread_attr_setschedpolicy
     (attr   : access pthread_attr_t;
      policy : int) return int;
   pragma Import (C, pthread_attr_setschedpolicy);

   function pthread_attr_setschedparam
     (attr        : access pthread_attr_t;
      sched_param : access struct_sched_param)
     return int;
   pragma Import (C, pthread_attr_setschedparam, "pthread_attr_setschedparam");

   function sched_yield return int;
   pragma Import (C, sched_yield, "sched_yield");

   ---------------------------
   -- P1003.1c - Section 16 --
   ---------------------------

   function pthread_attr_init (attributes : access pthread_attr_t) return int;
   pragma Import (C, pthread_attr_init, "pthread_attr_init");

   function pthread_attr_destroy
     (attributes : access pthread_attr_t) return int;
   pragma Import (C, pthread_attr_destroy, "pthread_attr_destroy");

   function pthread_attr_setdetachstate
     (attr        : access pthread_attr_t;
      detachstate : int) return int;
   pragma Import (C, pthread_attr_setdetachstate);

   function pthread_attr_setstacksize
     (attr      : access pthread_attr_t;
      stacksize : size_t) return int;
   pragma Import (C, pthread_attr_setstacksize, "pthread_attr_setstacksize");

   function pthread_create
     (thread        : access pthread_t;
      attributes    : access pthread_attr_t;
      start_routine : Thread_Body;
      arg           : System.Address) return int;
   pragma Import (C, pthread_create, "pthread_create");

   procedure pthread_exit (status : System.Address);
   pragma Import (C, pthread_exit, "pthread_exit");

   function pthread_self return pthread_t;
   pragma Import (C, pthread_self, "pthread_self");

   --------------------------
   -- POSIX.1c  Section 17 --
   --------------------------

   function pthread_setspecific
     (key   : pthread_key_t;
      value : System.Address) return int;
   pragma Import (C, pthread_setspecific, "pthread_setspecific");

   function pthread_getspecific (key : pthread_key_t) return System.Address;
   pragma Import (C, pthread_getspecific, "pthread_getspecific");

   type destructor_pointer is access procedure (arg : System.Address);

   function pthread_key_create
     (key        : access pthread_key_t;
      destructor : destructor_pointer) return int;
   pragma Import (C, pthread_key_create, "pthread_key_create");

   ---------------------------------------------------------------
   --  Non portable SGI 6.5 additions to the pthread interface  --
   --  must be executed from within the context of a system     --
   --  scope task                                               --
   ---------------------------------------------------------------

   function pthread_setrunon_np (cpu : int) return int;
   pragma Import (C, pthread_setrunon_np, "pthread_setrunon_np");

private

   type array_type_1 is array (Integer range 0 .. 3) of unsigned;
   type sigset_t is record
      X_X_sigbits : array_type_1;
   end record;
   pragma Convention (C, sigset_t);

   --  From <sys/ansi.h>
   type pid_t is new int32_t;

   type time_t is new int32_t;

   type timespec is record
      tv_sec : time_t;
      tv_nsec : long;
   end record;
   for timespec use record
      tv_sec at 0 range 0 .. 63;
      tv_nsec at 8 range 0 .. 63;
   end record;
   pragma Warnings (Off);
   --  There may be holes in the record, due to
   --  components not defined by POSIX standard.
   for timespec'Size use 128;
   pragma Convention (C, timespec);

   type suseconds_t is range -2**63 .. (2**63)-1;
   for suseconds_t'Size use 64;
   type struct_timeval is record
      tv_sec  : time_t;
      tv_usec : suseconds_t;
   end record;
   for struct_timeval use record
      tv_sec at 0 range 0 .. 63;
      tv_usec at 8 range 0 .. 63;
   end record;
   pragma Convention (C, struct_timeval);
   pragma Warnings (Off);
   --  There may be holes in the record, due to
   --  components not defined by POSIX standard.
   for struct_timeval'Size use 128;
   pragma Warnings (On);


   type array_type_9 is array (Integer range 0 .. 4) of long;
   type pthread_attr_t is record
      X_X_D : array_type_9;
   end record;
   pragma Convention (C, pthread_attr_t);

   type array_type_8 is array (Integer range 0 .. 1) of long;
   type pthread_condattr_t is record
      X_X_D : array_type_8;
   end record;
   pragma Convention (C, pthread_condattr_t);

   type array_type_7 is array (Integer range 0 .. 1) of long;
   type pthread_mutexattr_t is record
      X_X_D : array_type_7;
   end record;
   pragma Convention (C, pthread_mutexattr_t);

   type pthread_t is new System.Address;

   type array_type_10 is array (Integer range 0 .. 7) of long;
   type pthread_mutex_t is record
      X_X_D : array_type_10;
   end record;
   pragma Convention (C, pthread_mutex_t);

   type array_type_11 is array (Integer range 0 .. 7) of long;
   type pthread_cond_t is record
      X_X_D : array_type_11;
   end record;
   pragma Convention (C, pthread_cond_t);

   type pthread_key_t is new int;

end System.OS_Interface;
