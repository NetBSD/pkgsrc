# $NetBSD: find-pkgconfig-files.mk,v 1.5 2024/01/13 20:26:47 riastradh Exp $
#
# Copyright (c) 2020 The NetBSD Foundation, Inc.
# All rights reserved.
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
# pkg-config files in the base system.
#
# The following variables must be defined before including this file:
#
#    BUILTIN_FIND_PKGCONFIG_VAR is a list of variables to define.  These
#	variables take the value of the path to the file that is
#	"found".
#
#    BUILTIN_FIND_PKGCONFIG.<var> is the list of pkg-config files to find, in
#	order, on the ${BUILTIN_PKGCONFIG_DIRS}.  The variable <var> is set
#	to the first path "found" on the filesystem.
#
# After including this file, the following variables are defined:
#
#    <var> is the first of the pkg-config files listed in
#	${BUILTIN_FIND_PKGCONFIG.<var>} that is "found" in
#	${BUILTIN_PKGCONFIG_DIRS}, or else it is "__nonexistent__".
#
# An example use is:
#
# BUILTIN_FIND_PKGCONFIG_FILES_VAR:=	LIB1 LIB2
# BUILTIN_FIND_PKGCONFIG_FILES.LIB1:=	lib1.pc lib-1.0.pc
# BUILTIN_FIND_PKGCONFIG_FILES.LIB2:=	lib2.pc lib-2.0.pc
# .include "../../mk/buildlink3/find-pkgconfig-files.mk"
# .info ${LIB1}		# during development
# .info ${LIB2}		# during development
#
# Keywords: pkg-config pc

BUILTIN_PKGCONFIG_DIRS?=	/usr/lib/pkgconfig				\
				/usr/lib64/pkgconfig				\
				/usr/share/pkgconfig				\
			       	/usr/libdata/pkgconfig				\
				/usr/lib/x86_64-linux-gnu/pkgconfig		\
				/usr/lib/aarch64-linux-gnu/pkgconfig		\
				/usr/lib/arm-linux-gnueabi/pkgconfig		\
				/usr/lib/arm-linux-gnueabihf/pkgconfig		\
				/usr/lib/i386-linux-gnu/pkgconfig		\
				/usr/lib/mips64el-linux-gnuabi64/pkgconfig	\
				/usr/lib/mipsel-linux-gnu/pkgconfig		\
				/usr/lib/powerpc64le-linux-gnu/pkgconfig	\
				/usr/lib/s390x-linux-gnu/pkgconfig

.for _var_ in ${BUILTIN_FIND_PKGCONFIG_FILES_VAR}
.  if !defined(${_var_})
${_var_}= __nonexistent__
.    for _file_ in ${BUILTIN_FIND_PKGCONFIG_FILES.${_var_}}
.      for _dir_ in ${BUILTIN_PKGCONFIG_DIRS}
.        if !empty(${_var_}:M__nonexistent__) && \
            exists(${TOOLS_CROSS_DESTDIR}${_dir_}/${_file_})
${_var_}= ${_dir_}/${_file_}
.        endif
.      endfor
.    endfor
.  endif
MAKEVARS+=	${_var_}
.endfor
