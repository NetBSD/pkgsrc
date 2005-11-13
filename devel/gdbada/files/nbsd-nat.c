/* Low level Unix child interface to ptrace, for GDB when running under Unix.
   Copyright 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996,
   1998, 1999, 2000, 2001, 2002
   Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#include "defs.h"
#include "frame.h"
#include "inferior.h"
#include "target.h"
#include "gdb_string.h"
#include "regcache.h"

#include "gdb_wait.h"

#include "command.h"

#include <sys/types.h>
#include "gdb_dirent.h"
#include <sys/ptrace.h>
#include <machine/reg.h>
#include "i386-tdep.h"

#define ATTACH_DETACH
/* Start debugging the process whose number is PID.  */
int
attach (int pid)
{
  errno = 0;
  if (pid == getpid())
  	ptrace (PT_TRACE_ME, pid, (PTRACE_ARG3_TYPE) 0, 0);
  else
  	ptrace (PT_ATTACH, pid, (PTRACE_ARG3_TYPE) 0, 0);
  if (errno)
    perror_with_name ("ptrace");
  attach_flag = 1;
  return pid;
}
