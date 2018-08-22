# $NetBSD: find-headers.mk,v 1.3 2018/08/22 20:48:36 maya Exp $
#
# Copyright (c) 2005 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

#
# This is a "subroutine" that can be included to detect the presence of
# header files in the base system.
#
# The following variables must be defined before including this file:
#
#    BUILTIN_FIND_HEADERS_VAR is a list of variables to define.  These
#	variables take the value of the path to the file that is
#	"found".
#
#    BUILTIN_FIND_HEADERS.<var> is the list of header files to find, in
#	order, on the ${BUILTIN_INCLUDE_DIRS}.  The variable <var> is set
#	to the first path "found" on the filesystem.
#
# Optionally, the following variables may also be defined:
#
#    BUILTIN_FIND_GREP.<var> is a regular expression that must be
#	matched within a file in order for the file to be considered
#	"found".  If it isn't defined, then we simply check for the
#	existence of the file.
#
# After including this file, the following variables are defined:
#
#    <var> is the first of the header file listed in
#	${BUILTIN_FIND_HEADERS.<var>} that is "found" in
#	${BUILTIN_INCLUDE_DIRS}, or else it is "__nonexistent__".
#
# An example use is:
#
# BUILTIN_FIND_HEADERS_VAR:=	FOO BAR
#
# BUILTIN_FIND_HEADERS.FOO=	header1.h header2.h
# BUILTIN_FIND_GREP.FOO=	\#define.*FOO
#
# BUILTIN_FIND_HEADERS.BAR=	header3.h heaer/4.h
# .include "../../mk/buildlink3/builtin-files.mk"
#

.if empty(USE_TOOLS:Mecho)
USE_TOOLS+=	echo
.endif
.if empty(USE_TOOLS:Mgrep)
USE_TOOLS+=	grep
.endif

BUILTIN_INCLUDE_DIRS?=	${COMPILER_INCLUDE_DIRS} ${"${X11_TYPE:Mnative}":?${X11BASE}/include:}

.for _var_ in ${BUILTIN_FIND_HEADERS_VAR}
.  if !defined(${_var_})
${_var_}=	__nonexistent__
.    for _file_ in ${BUILTIN_FIND_HEADERS.${_var_}}
.      for _dir_ in ${BUILTIN_INCLUDE_DIRS}
.        if !empty(${_var_}:M__nonexistent__) && exists(${_dir_}/${_file_})
.          if !defined(BUILTIN_FIND_GREP.${_var_})
${_var_}=	${_dir_}/${_file_}
.          else
${_var_}!=								\
  	if ${GREP} -q ${BUILTIN_FIND_GREP.${_var_}:Q} ${_dir_:Q}/${_file_:Q}; then	\
		${ECHO} ${_dir_:Q}/${_file_:Q};				\
	else								\
		${ECHO} __nonexistent__;				\
	fi
.          endif
.        endif
.      endfor
.    endfor
.  endif
MAKEVARS+=	${_var_}
.endfor
