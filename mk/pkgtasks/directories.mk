# $NetBSD: directories.mk,v 1.1 2017/06/01 02:06:04 jlam Exp $
#
# Copyright (c) 2017 The NetBSD Foundation, Inc.
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

# Generate the data file for the directories package task.

# MAKE_DIRS
# OWN_DIRS
# REQD_DIRS
#	List of directories that should be created and destroyed when
#	the package is installed and removed.
#
#	OWN_DIRS is for directories owned by the package and the user
#	is prompted to remove the directory if it isn't empty.  The
#	directories are created or removed only if PKG_CONFIG is "yes".
#
#	MAKE_DIRS is for directories used by the package and the user
#	is never prompted to remove non-empty directories.  The
#	directories are created or removed only if PKG_CONFIG is "yes".
#
#	REQD_DIRS is for directories used by the package that must
#	always be created (PKG_CONFIG is ignored), and the user is
#	never prompted to remove non-empty directories.  All
#	directories listed in REQD_DIRS should be under ${PREFIX}.
#	The use-case for REQD_DIRS is very specialized, and most
#	packages should be using either OWN_DIRS or MAKE_DIRS instead.
#
#	If the directory pathname is a relative path, then it is taken
#	to be relative to ${PREFIX}.
#
# MAKE_DIRS_PERMS
# OWN_DIRS_PERMS
# REQD_DIRS_PERMS
#	List of sublists representing directories with ownership and
#	explicit modes that should be created and destroyed when the
#	package is installed and removed.  The sublists are of the
#	form:
#
#		<directory> <owner> <group> <mode>
#
#	These variables have the same usage as the similarly-named
#	variables that don't end in "_PERMS".
#
_PKG_VARS.pkgtasks+=	MAKE_DIRS MAKE_DIRS_PERMS \
			OWN_DIRS OWN_DIRS_PERMS \
			REQD_DIRS REQD_DIRS_PERMS
MAKE_DIRS?=		# empty
MAKE_DIRS_PERMS?=	# empty
OWN_DIRS?=		# empty
OWN_DIRS_PERMS?=	# empty
REQD_DIRS?=		# empty
REQD_DIRS_PERMS?=	# empty

# Trigger pkgtasks dependency if needed.
_PKGTASKS_DATAVARS.directories=		\
	MAKE_DIRS MAKE_DIRS_PERMS	\
	OWN_DIRS OWN_DIRS_PERMS		\
	REQD_DIRS REQD_DIRS_PERMS
.for _var_ in ${_PKGTASKS_DATAVARS.directories}
.  if !empty(${_var_})
USE_PKGTASKS=		yes
.  endif
.endfor

# Strip leading "${PREFIX}/" from the directory pathnames.
_MAKE_DIRS=		${MAKE_DIRS:S|^${PREFIX}/||g}
_MAKE_DIRS_PERMS=	${MAKE_DIRS_PERMS:S|^${PREFIX}/||g}
_OWN_DIRS=		${OWN_DIRS:S|^${PREFIX}/||g}
_OWN_DIRS_PERMS=	${OWN_DIRS_PERMS:S|^${PREFIX}/||g}
_REQD_DIRS=		${REQD_DIRS:S|^${PREFIX}/||g}
_REQD_DIRS_PERMS=	${REQD_DIRS_PERMS:S|^${PREFIX}/||g}

# Assert that the variables have the right number of words and
# that no directory is listed in more than one variable.
#
_ALL_DIRS.directories=	# empty
.for _var_ in MAKE_DIRS OWN_DIRS REQD_DIRS
.  for d in ${${_var_}}
_DIRS.${d}+=		${_var_}
_ALL_DIRS.directories+=	${d}
.  endfor
.endfor
.for _var_ in MAKE_DIRS_PERMS OWN_DIRS_PERMS REQD_DIRS_PERMS
.  if empty(${_var_}) || empty(${_var_}:C/.*/4/:M*:S/4 4 4 4//gW)
# ${_var_} has a multiple of 4 words.
.    for d o g m in ${${_var_}}
_DIRS.${d}+=		${_var_}
_ALL_DIRS.directories+=	${d}
.    endfor
.  else
PKG_FAIL_REASON+=	${_var_:Q}" must have a multiple of 4 words."
.  endif
.endfor
.for d in ${_ALL_DIRS.directories:O:u}
.  if ${_DIRS.${d}:[#]} != 1
PKG_FAIL_REASON+=	${d:Q}" is listed more than once: "${_DIRS.${d}:Q}
.  endif
.endfor

_PKGTASKS_DATA.directories=	${_PKGTASKS_DIR}/directories
_PKGTASKS_DATAFILES+=		${_PKGTASKS_DATA.directories}

${_PKGTASKS_DATA.directories}:
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}exec > ${.TARGET:Q}.tmp
	${RUN}set -- args ${_MAKE_DIRS}; shift;				\
	while ${TEST} "$$#" -gt 0; do					\
		dir="$$1"; shift;					\
		${ECHO} "# DIR: $$dir m" >> ${.TARGET:Q}.tmp;		\
	done
	${RUN}set -- args ${_MAKE_DIRS_PERMS}; shift;			\
	while ${TEST} "$$#" -gt 0; do					\
		dir="$$1"; owner="$$2"; group="$$3"; mode="$$4"; shift 4; \
		${ECHO} "# DIR: $$dir m $$mode $$owner $$group"		\
			>> ${.TARGET:Q}.tmp;				\
	done
	${RUN}set -- args ${_OWN_DIRS}; shift;				\
	while ${TEST} "$$#" -gt 0; do					\
		dir="$$1"; shift;					\
		${ECHO} "# DIR: $$dir mo" >> ${.TARGET:Q}.tmp;		\
	done
	${RUN}set -- args ${_OWN_DIRS_PERMS}; shift;			\
	while ${TEST} "$$#" -gt 0; do					\
		dir="$$1"; owner="$$2"; group="$$3"; mode="$$4"; shift 4; \
		${ECHO} "# DIR: $$dir mo $$mode $$owner $$group"	\
			>> ${.TARGET:Q}.tmp;				\
	done
	${RUN}set -- args ${_REQD_DIRS}; shift;				\
	while ${TEST} "$$#" -gt 0; do					\
		dir="$$1"; shift;					\
		${ECHO} "# DIR: $$dir fm" >> ${.TARGET:Q}.tmp;		\
	done
	${RUN}set -- args ${_REQD_DIRS_PERMS}; shift;			\
	while ${TEST} "$$#" -gt 0; do					\
		dir="$$1"; owner="$$2"; group="$$3"; mode="$$4"; shift 4; \
		${ECHO} "# DIR: $$dir fm $$mode $$owner $$group"	\
			>> ${.TARGET:Q}.tmp;				\
	done
	${RUN}${MV} ${.TARGET:Q}.tmp ${.TARGET:Q}
