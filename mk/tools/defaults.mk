# $NetBSD: defaults.mk,v 1.59 2013/11/06 13:12:50 obache Exp $
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
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#        This product includes software developed by the NetBSD
#        Foundation, Inc. and its contributors.
# 4. Neither the name of The NetBSD Foundation nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
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

.if !defined(TOOLS_DEFAULTS_MK)
TOOLS_DEFAULTS_MK=	defined

# These are the platform-specific lists of system-supplied tools.
#
# XXX These should eventually just migrate over to the appropriate
# XXX pkgsrc/mk/platform/${OPSYS}.mk file.
#
.if exists(${_PKGSRC_TOPDIR}/mk/tools/tools.${OPSYS}.mk)
.  include "${_PKGSRC_TOPDIR}/mk/tools/tools.${OPSYS}.mk"
.endif

######################################################################

# "TOOL" variable names associated with each of the tools

_TOOLS_VARNAME.awk=		AWK
_TOOLS_VARNAME.basename=	BASENAME
_TOOLS_VARNAME.bash=		BASH
_TOOLS_VARNAME.bison-yacc=	YACC
_TOOLS_VARNAME.byacc=		YACC
_TOOLS_VARNAME.bzcat=		BZCAT
_TOOLS_VARNAME.bzip2=		BZIP2
_TOOLS_VARNAME.cat=		CAT
_TOOLS_VARNAME.chgrp=		CHGRP
_TOOLS_VARNAME.chmod=		CHMOD
_TOOLS_VARNAME.chown=		CHOWN
_TOOLS_VARNAME.cmake=		CMAKE
_TOOLS_VARNAME.cmp=		CMP
_TOOLS_VARNAME.cp=		CP
_TOOLS_VARNAME.cpack=		CPACK
_TOOLS_VARNAME.csh=		CSH
_TOOLS_VARNAME.cut=		CUT
_TOOLS_VARNAME.date=		DATE
_TOOLS_VARNAME.diff=		DIFF
_TOOLS_VARNAME.digest=		DIGEST
_TOOLS_VARNAME.dirname=		DIRNAME
_TOOLS_VARNAME.echo=		ECHO
_TOOLS_VARNAME.egrep=		EGREP
_TOOLS_VARNAME.env=		SETENV
_TOOLS_VARNAME.expr=		EXPR
_TOOLS_VARNAME.false=		FALSE
_TOOLS_VARNAME.fgrep=		FGREP
_TOOLS_VARNAME.file=		FILE_CMD
_TOOLS_VARNAME.find=		FIND
_TOOLS_VARNAME.gawk=		AWK
_TOOLS_VARNAME.gem=		GEM
_TOOLS_VARNAME.gm4=		M4
_TOOLS_VARNAME.gmake=		GMAKE
_TOOLS_VARNAME.grep=		GREP
_TOOLS_VARNAME.gsed=		SED
_TOOLS_VARNAME.gsoelim=		SOELIM
_TOOLS_VARNAME.gtar=		GTAR
_TOOLS_VARNAME.gunzip=		GUNZIP_CMD
_TOOLS_VARNAME.gzcat=		GZCAT
_TOOLS_VARNAME.gzip=		GZIP_CMD
_TOOLS_VARNAME.head=		HEAD
_TOOLS_VARNAME.hostname=	HOSTNAME_CMD
_TOOLS_VARNAME.id=		ID
_TOOLS_VARNAME.ident=		IDENT
_TOOLS_VARNAME.imake=		IMAKE
_TOOLS_VARNAME.install=		INSTALL
_TOOLS_VARNAME.install-info=	INSTALL_INFO
_TOOLS_VARNAME.lex=		LEX
_TOOLS_VARNAME.lha=		LHA
_TOOLS_VARNAME.ln=		LN
_TOOLS_VARNAME.ls=		LS
_TOOLS_VARNAME.lzcat=		LZCAT
_TOOLS_VARNAME.m4=		M4
_TOOLS_VARNAME.mail=		MAIL_CMD
_TOOLS_VARNAME.makeinfo=	MAKEINFO
_TOOLS_VARNAME.mkdir=		MKDIR
_TOOLS_VARNAME.mktemp=		MKTEMP
_TOOLS_VARNAME.mtree=		MTREE
_TOOLS_VARNAME.mv=		MV
_TOOLS_VARNAME.nice=		NICE
_TOOLS_VARNAME.nroff=		NROFF
_TOOLS_VARNAME.openssl=		OPENSSL
_TOOLS_VARNAME.7za=		P7ZA
_TOOLS_VARNAME.patch=		PATCH
_TOOLS_VARNAME.pax=		PAX
_TOOLS_VARNAME.perl=		PERL5
_TOOLS_VARNAME.pod2man=		POD2MAN
_TOOLS_VARNAME.printf=		PRINTF
_TOOLS_VARNAME.pwd=		PWD_CMD
_TOOLS_VARNAME.rm=		RM
_TOOLS_VARNAME.rmdir=		RMDIR
_TOOLS_VARNAME.rpm2pkg=		RPM2PKG
_TOOLS_VARNAME.sed=		SED
_TOOLS_VARNAME.sh=		SH
_TOOLS_VARNAME.shlock=		SHLOCK
_TOOLS_VARNAME.sleep=		SLEEP
_TOOLS_VARNAME.soelim=		SOELIM
_TOOLS_VARNAME.sort=		SORT
_TOOLS_VARNAME.tail=		TAIL
_TOOLS_VARNAME.tar=		TAR
_TOOLS_VARNAME.tbl=		TBL
_TOOLS_VARNAME.tclsh=		TCLSH
_TOOLS_VARNAME.tee=		TEE
_TOOLS_VARNAME.test=		TEST
_TOOLS_VARNAME.touch=		TOUCH
_TOOLS_VARNAME.tr=		TR
_TOOLS_VARNAME.true=		TRUE
_TOOLS_VARNAME.tsort=		TSORT
_TOOLS_VARNAME.unrar=		UNRAR
_TOOLS_VARNAME.unzip=		UNZIP_CMD
_TOOLS_VARNAME.unzoo=		UNZOO
_TOOLS_VARNAME.wc=		WC
_TOOLS_VARNAME.wish=		WISH
_TOOLS_VARNAME.xargs=		XARGS
_TOOLS_VARNAME.xmkmf=		XMKMF_CMD
_TOOLS_VARNAME.xzcat=		XZ
_TOOLS_VARNAME.xzcat=		XZCAT
_TOOLS_VARNAME.yacc=		YACC

######################################################################

# "TOOL" variable names associated with each of the tools that are
# expected by GNU configure script.

_TOOLS_VARNAME_GNU.awk=		AWK
_TOOLS_VARNAME_GNU.bison-yacc=	YACC
_TOOLS_VARNAME_GNU.byacc=	YACC
_TOOLS_VARNAME_GNU.cat=		CAT ac_cv_path_CAT
_TOOLS_VARNAME_GNU.chmod=	CHMOD
_TOOLS_VARNAME_GNU.cmp=		CMP
_TOOLS_VARNAME_GNU.cp=		CP
_TOOLS_VARNAME_GNU.diff=	DIFF
_TOOLS_VARNAME_GNU.echo=	ECHO ac_cv_path_ECHO
_TOOLS_VARNAME_GNU.egrep=	EGREP ac_cv_path_EGREP
_TOOLS_VARNAME_GNU.env=		SETENV ENV_PROG ac_cv_path_ENV
_TOOLS_VARNAME_GNU.false=	FALSE ac_cv_path_FALSE
_TOOLS_VARNAME_GNU.find=	FIND
_TOOLS_VARNAME_GNU.gawk=	AWK
_TOOLS_VARNAME_GNU.gm4=		M4
_TOOLS_VARNAME_GNU.grep=	GREP ac_cv_path_GREP
_TOOLS_VARNAME_GNU.gsed=	SED
_TOOLS_VARNAME_GNU.gtar=	TAR
_TOOLS_VARNAME_GNU.hostname=	HOSTNAME
_TOOLS_VARNAME_GNU.lex=		LEX
_TOOLS_VARNAME_GNU.ln=		LN
_TOOLS_VARNAME_GNU.ls=		LS
_TOOLS_VARNAME_GNU.m4=		M4
_TOOLS_VARNAME_GNU.mkdir=	MKDIR
_TOOLS_VARNAME_GNU.mv=		MV
_TOOLS_VARNAME_GNU.perl=	PERL PERL_PATH
_TOOLS_VARNAME_GNU.rm=		RM
_TOOLS_VARNAME_GNU.rmdir=	RMDIR
_TOOLS_VARNAME_GNU.sed=		SED
_TOOLS_VARNAME_GNU.sort=	SORT
_TOOLS_VARNAME_GNU.tar=		TAR
_TOOLS_VARNAME_GNU.tclsh=	TCLSH
_TOOLS_VARNAME_GNU.test=	TEST ac_cv_path_TEST
_TOOLS_VARNAME_GNU.touch=	TOUCH
_TOOLS_VARNAME_GNU.tr=		TR
_TOOLS_VARNAME_GNU.true=	TRUE ac_cv_path_TRUE
_TOOLS_VARNAME_GNU.wish=	WISH
_TOOLS_VARNAME_GNU.xmkmf=	XMKMF
_TOOLS_VARNAME_GNU.yacc=	YACC

######################################################################

# Set a default value for the TOOL names for each of the tools we
# claim we'll use in USE_TOOLS to point to the platform command, e.g.,
# TBL, YACC, etc.  These tools are used in the top-level make(1), not
# just in the targets, so these must be defined here, and this file be
# included by bsd.prefs.mk.
#
.for _t_ in ${USE_TOOLS:C/:.*//:O:u}
.  if defined(_TOOLS_VARNAME.${_t_}) && \
      defined(TOOLS_PLATFORM.${_t_}) && !empty(TOOLS_PLATFORM.${_t_})
.    for _v_ in ${_TOOLS_VARNAME.${_t_}}
${_v_}?=	${TOOLS_PLATFORM.${_t_}}
.    endfor
.  endif
.endfor

.endif	# TOOLS_DEFAULTS_MK
