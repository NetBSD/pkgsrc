# $NetBSD: scripts.mk,v 1.3 2017/06/07 20:24:01 jlam Exp $
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

# This Makefile fragment provides the targets to make the +DEINSTALL
# and +INSTALL scripts and hooks into metadata.mk to automatically
# generate them as needed.

# HEADER_TEMPLATES
#	List of package-provided template files to be concatenated
#	into a header for the install and deinstall scripts.  The
#	concatenated files are placed after the main header template
#	file.
#
# DEINSTALL_TEMPLATES
#	List of package-provided template files to be concatenated
#	to form the body of the deinstall script.  The concatenated
#	files are placed before the main deinstall template file.
#	The script templates should exit with a code >0 if an error
#	occurs.
#
# INSTALL_TEMPLATES
#	List of package-provided template files to be concatenated
#	to form the body of the install script.  The concatenated
#	files are placed after the main install template file.  The
#	script templates should exit with a code >0 if an error
#	occurs.
#
_HEADER_TMPL=		${PKGSRCDIR}/mk/pkgformat/pkg/templates/header
HEADER_TEMPLATES?=	# empty
.for _file_ in ${PKGDIR}/HEADER
.  if exists(${_file_}) && empty(HEADER_TEMPLATES:M${_file_})
HEADER_TEMPLATES+=	${_file_}
.  endif
.endfor
_DEINSTALL_TMPL=	${PKGSRCDIR}/mk/pkgformat/pkg/templates/deinstall
DEINSTALL_TEMPLATES?=	# empty
.for _file_ in ${PKGDIR}/DEINSTALL
.  if exists(${_file_}) && empty(DEINSTALL_TEMPLATES:M${_file_})
DEINSTALL_TEMPLATES+=	${_file_}
.  endif
.endfor
_INSTALL_TMPL=		${PKGSRCDIR}/mk/pkgformat/pkg/templates/install
INSTALL_TEMPLATES?=	# empty
.for _file_ in ${PKGDIR}/INSTALL
.  if exists(${_file_}) && empty(INSTALL_TEMPLATES:M${_file_})
INSTALL_TEMPLATES+=	${_file_}
.  endif
.endfor
_FOOTER_TMPL?=		${PKGSRCDIR}/mk/pkgformat/pkg/templates/footer

# DEINSTALL_SRC
# INSTALL_SRC
#	List of source files that are concatenated to form the
#	deinstall and install scripts.
#
.if ( "${USE_PKGTASKS:tl}" == "yes" ) || !empty(HEADER_TEMPLATES) ||	\
    !empty(DEINSTALL_TEMPLATES) || !empty(INSTALL_TEMPLATES)
USE_PKGTASKS=		yes	# script templates use pkgtasks
DEINSTALL_SRC?=		${_HEADER_TMPL} ${HEADER_TEMPLATES}		\
			${DEINSTALL_TEMPLATES} ${_DEINSTALL_TMPL}	\
			${_FOOTER_TMPL} ${PKGTASKS_DATAFILE}
INSTALL_SRC?=		${_HEADER_TMPL} ${HEADER_TEMPLATES}		\
			${_INSTALL_TMPL} ${INSTALL_TEMPLATES}		\
			${_FOOTER_TMPL} ${PKGTASKS_DATAFILE}
.else
DEINSTALL_SRC?=		# empty
INSTALL_SRC?=		# empty
.endif

# _DEINSTALL_FILE
#	The location of the file to be added as the deinstall script
#	for the package.
#
#	Possible: any valid path
#	Default: ${PKG_DB_TMPDIR}/+DEINSTALL
#
# _INSTALL_FILE
#	The location of the file to be added as the install script
#	for the package.
#
#	Possible: any valid path
#	Default: ${PKG_DB_TMPDIR}/+INSTALL
#
# _pkgformat-generate-install-scripts (PRIVATE)
#	Convenience target to generate the deinstall and install
#	scripts for the package.
#

.if !empty(DEINSTALL_SRC)
_DEINSTALL_FILE=	${PKG_DB_TMPDIR}/+DEINSTALL

${_DEINSTALL_FILE}: ${DEINSTALL_SRC}
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}${CAT} ${.ALLSRC} | ${SED} ${FILES_SUBST_SED} > ${.TARGET}.tmp
	${RUN}${CHMOD} +x ${.TARGET}.tmp
	${RUN}${MV} -f ${.TARGET}.tmp ${.TARGET}
.endif
.if !empty(INSTALL_SRC)
_INSTALL_FILE=		${PKG_DB_TMPDIR}/+INSTALL

${_INSTALL_FILE}: ${INSTALL_SRC}
	${RUN}${MKDIR} ${.TARGET:H:Q}
	${RUN}${CAT} ${.ALLSRC} | ${SED} ${FILES_SUBST_SED} > ${.TARGET}.tmp
	${RUN}${CHMOD} +x ${.TARGET}.tmp
	${RUN}${MV} -f ${.TARGET}.tmp ${.TARGET}
.endif

.PHONY: _pkgformat-generate-install-scripts
_pkgformat-generate-install-scripts: ${_DEINSTALL_FILE} ${_INSTALL_FILE}

# Hook into pkgsrc/mk/pkgformat/pkg/metadata.mk to automatically generate
# the deinstall and install scripts if needed.
#
_METADATA_TARGETS+=	${_DEINSTALL_FILE} ${_INSTALL_FILE}

###
# Variable substitutions for the scripts.

FILES_SUBST+=	PKGBASE=${PKGBASE:Q}

# Variables for programs for use by script templates.
FILES_SUBST+=	BASENAME=${BASENAME:Q}
FILES_SUBST+=	CHGRP=${CHGRP:Q}
FILES_SUBST+=	CMP=${CMP:Q}
FILES_SUBST+=	DIRNAME=${DIRNAME:Q}
FILES_SUBST+=	ECHO=${ECHO:Q}
FILES_SUBST+=	ECHO_N=${ECHO_N:Q}
FILES_SUBST+=	EGREP=${EGREP:Q}
FILES_SUBST+=	EXPR=${EXPR:Q}
FILES_SUBST+=	FALSE=${FALSE:Q}
FILES_SUBST+=	GREP=${GREP:Q}
FILES_SUBST+=	GTAR=${GTAR:Q}
FILES_SUBST+=	HEAD=${HEAD:Q}
FILES_SUBST+=	PERL5=${PERL5:Q}
FILES_SUBST+=	PWD_CMD=${PWD_CMD:Q}
FILES_SUBST+=	SETENV=${SETENV:Q}
FILES_SUBST+=	SH=${SH:Q}
FILES_SUBST+=	SU=${SU:Q}
FILES_SUBST+=	TEST=${TEST:Q}
FILES_SUBST+=	TOUCH=${TOUCH:Q}
FILES_SUBST+=	TR=${TR:Q}
FILES_SUBST+=	TRUE=${TRUE:Q}
FILES_SUBST+=	XARGS=${XARGS:Q}

# Variables for the pkg_install package tools.
FILES_SUBST+=	PKG_ADMIN=${PKG_ADMIN:Q}
FILES_SUBST+=	PKG_INFO=${PKG_INFO:Q}

# Variables for installation prefix references.
FILES_SUBST+=	CROSSBASE=${CROSSBASE:Q}
FILES_SUBST+=	LOCALBASE=${LOCALBASE:Q}
FILES_SUBST+=	X11BASE=${X11BASE:Q}
FILES_SUBST+=	PREFIX=${PREFIX:Q}

# Variables for the package configuration directory.
FILES_SUBST+=	PKG_SYSCONFBASE=${PKG_SYSCONFBASE:Q}
FILES_SUBST+=	PKG_SYSCONFBASEDIR=${PKG_SYSCONFBASEDIR:Q}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

# Variables for the local state directory.
FILES_SUBST+=	VARBASE=${VARBASE:Q}
