# $NetBSD: bsd.pkgtasks.mk,v 1.1 2017/06/01 02:06:04 jlam Exp $
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

_VARGROUPS+=	pkgtasks

# PKG_CONFIG
#	User-settable variable for whether the directory- and
#	file-handling should be performed automatically, or if the
#	user should be warned instead.
#
#	Possible: yes, no (case-insensitive)
#	Default: yes
#
# PKG_CONFIG_PERMS
#	User-settable variable for whether to set permissions and
#	ownership on files and directories, or if the user should be
#	warned instead.
#
#	Possible: yes, no (case-insensitive)
#	Default: yes
#
# PKG_CREATE_USERGROUP
#	User-settable variable for whether groups and users should be
#	added automatically, or if the user should be warned instead.
#
#	Possible: yes, no (case-insensitive)
#	Default: yes
#
# PKG_INIT_SCRIPTS
#	User-settable variable for whether to copy init scripts into
#	the appropriate places for the init system to locate them,
#	e.g., copy rc.d scripts to ${RCD_SCRIPTS_DIR}, or if the user
#	should be warned instead.
#
#	Possible: yes, no (case-insensitive)
#	Default: yes
#
# PKG_REGISTER_SHELLS
#	User-settable variable for whether to register shells in the
#	login shell database (/etc/shells) automatically, or if the
#	user should be warned instead.
#
#	Possible: yes, no (case-insensitive)
#	Default: yes
#
# PKG_UPDATE_FONTS_DB
#	User-settable variable for whether to update the databases in
#	fonts directories automatically, or if the user should be
#	warned instead.
#
#	Possible: yes, no (case-insensitive)
#	Default: yes
#
_USER_VARS.pkgtasks+=	PKG_CONFIG PKG_CONFIG_PERMS PKG_INIT_SCRIPTS
PKG_CONFIG?=		yes
PKG_CONFIG_PERMS?=	no
PKG_CREATE_USERGROUP?=	yes
PKG_INIT_SCRIPTS?=	${PKG_RCD_SCRIPTS:Uno}	# deprecated
PKG_REGISTER_SHELLS?=	yes
PKG_UPDATE_FONTS_DB?=	yes
FILES_SUBST+=		PKG_CONFIG=${PKG_CONFIG:tl:Q}
FILES_SUBST+=		PKG_CONFIG_PERMS=${PKG_CONFIG_PERMS:tl:Q}
FILES_SUBST+=		PKG_CREATE_USERGROUP=${PKG_CREATE_USERGROUP:tl:Q}
FILES_SUBST+=		PKG_INIT_SCRIPTS=${PKG_INIT_SCRIPTS:tl:Q}
FILES_SUBST+=		PKG_REGISTER_SHELLS=${PKG_REGISTER_SHELLS:tl:Q}
FILES_SUBST+=		PKG_UPDATE_FONTS_DB=${PKG_UPDATE_FONTS_DB:tl:Q}

# FILES_SUBST
#	Package-settable varibable that lists "variable=value" pairs
#	that is turned into a sed(1) script for substituting
#	"@variable@" with "value".
#
# FILES_SUBST_SED
#	System variable set by this file that is list of
#	"variable=value" pairs in ${FILES_SUBST} turned into a sed(1)
#	script for substituting "@variable@" with "value".
#
_PKG_VARS.pkgtasks+=	FILES_SUBST
_SYS_VARS.pkgtasks+=	FILES_SUBST_SED
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

# PKG_REFCOUNT_DBDIR
#	The location of the reference-count database directory used
#	by installed packages.
#
#	Possible: any valid directory path
#	Default: ${PKG_DBDIR}.refcount
#
PKG_REFCOUNT_DBDIR?=	${PKG_DBDIR}.refcount
FILES_SUBST+=		PKG_PREFIX=${PREFIX:Q}
FILES_SUBST+=		PKG_REFCOUNT_DBDIR=${PKG_REFCOUNT_DBDIR:Q}

# Directory to hold the built objects.
_PKGTASKS_DIR=	${WRKDIR}/.pkgtasks

# List of generated task data files.
_PKGTASKS_DATAFILES=	# empty

# USE_PKGTASKS
#	Public variable set by this file that indicates whether
#	package tasks are needed.
#
#	Possible: yes, no
#
_SYS_VARS.pkgtasks=	USE_PKGTASKS
USE_PKGTASKS=		no

.include "${PKGSRCDIR}/mk/pkgtasks/directories.mk"
.include "${PKGSRCDIR}/mk/pkgtasks/files.mk"
.include "${PKGSRCDIR}/mk/pkgtasks/fonts.mk"
.include "${PKGSRCDIR}/mk/pkgtasks/info_files.mk"
.include "${PKGSRCDIR}/mk/pkgtasks/ocaml_findlib.mk"
.include "${PKGSRCDIR}/mk/pkgtasks/permissions.mk"
.include "${PKGSRCDIR}/mk/pkgtasks/shells.mk"
.include "${PKGSRCDIR}/mk/pkgtasks/shlibs.mk"
.include "${PKGSRCDIR}/mk/pkgtasks/usergroup.mk"

# Add a dependency on pkgtasks if package tasks are needed.
.if "${USE_PKGTASKS:tl}" == "yes"
DEPENDS+=		pkgtasks-1>=1.9:../../pkgtools/pkgtasks
.endif
TASK_MODULE_DIR?=	${LOCALBASE}/share/pkgtasks-1

# PKGTASKS_DATAFILE
#	The formatted data file for use by pkgtools/pkgtasks.
#
_SYS_VARS.pkgtasks=	PKGTASKS_DATAFILE
PKGTASKS_DATAFILE=	${_PKGTASKS_DIR}/pkgtasks-datafile

${PKGTASKS_DATAFILE}: ${_PKGTASKS_DATAFILES}
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}${CAT} ${.ALLSRC} > ${.TARGET:Q}.tmp
	${RUN}${MV} ${.TARGET:Q}.tmp ${.TARGET:Q}

.PHONY: pkgtasks
pkgtasks: ${PKGTASKS_DATAFILE}

# Variables for programs used by pkgtasks.
FILES_SUBST+=	AWK=${AWK:Q}
FILES_SUBST+=	CAT=${CAT:Q}
FILES_SUBST+=	CHMOD=${CHMOD:Q}
FILES_SUBST+=	CHOWN=${CHOWN:Q}
FILES_SUBST+=	CP=${CP:Q}
FILES_SUBST+=	DATE=${DATE:Q}
FILES_SUBST+=	FIND=${FIND:Q}
FILES_SUBST+=	ID=${ID:Q}
FILES_SUBST+=	LDCONFIG=${LDCONFIG:Q}
FILES_SUBST+=	LN=${LN:Q}
FILES_SUBST+=	LS=${LS:Q}
FILES_SUBST+=	MKDIR=${MKDIR:Q}
FILES_SUBST+=	MKTEMP=${MKTEMP:Q}
FILES_SUBST+=	MV=${MV:Q}
FILES_SUBST+=	PRINTF=${PRINTF:Q}
FILES_SUBST+=	RM=${RM:Q}
FILES_SUBST+=	RMDIR=${RMDIR:Q}
FILES_SUBST+=	SED=${SED:Q}
FILES_SUBST+=	SORT=${SORT:Q}
FILES_SUBST+=	UNAME=${UNAME:Q}

# Variables for addgroup/adduser programs used by pkgtasks.
FILES_SUBST+=	GROUPADD=${GROUPADD:Q}
FILES_SUBST+=	PW=${PW:Q}		# DragonFly, FreeBSD
FILES_SUBST+=	PWD_MKDB=${PWD_MKDB:Q}	# MirBSD
FILES_SUBST+=	USERADD=${USERADD:Q}
