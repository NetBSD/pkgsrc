# $NetBSD: texinfo.mk,v 1.32 2006/03/05 16:27:29 jlam Exp $

#
# This Makefile fragment is included by bsd.pkg.mk when INFO_FILES is
# not empty.
#

.if !defined(TEXINFO_MK)
TEXINFO_MK=	# defined

.if !empty(INFO_FILES)
#
# Handle install-info.
# 

# Pathname relative to ${PREFIX} of directory holding the info
# files and the Info dir file.
INFO_DIR?=	info

# Does the system have the install-info command?
# Any version will fit (really?).
_INSTALL_INFO=
.  for _i_ in /usr/bin/install-info /sbin/install-info
.    if exists(${_i_}) && (${LOCALBASE} != ${_i_:C|/[^/]+/install-info$||})
_INSTALL_INFO=			${_i_}
.    endif
.  endfor

# If no install-info was found provide one with the pkg_install-info package.
# And set INSTALL_INFO to the install-info command it provides.
.  if empty(_INSTALL_INFO)
_PKG_INSTALL_INFO_PREFIX_DEFAULT=	${LOCALBASE}
DEPENDS+=	pkg_install-info-[0-9]*:../../pkgtools/pkg_install-info
EVAL_PREFIX+=	_PKG_INSTALL_INFO_PREFIX=pkg_install-info
INSTALL_INFO=	${_PKG_INSTALL_INFO_PREFIX}/bin/pkg_install-info
.  else
INSTALL_INFO=	${_INSTALL_INFO}
.  endif

# Generate INSTALL/DEINSTALL scripts code for handling install-info.
INSTALL_EXTRA_TMPL+=	${.CURDIR}/../../mk/install/install-info
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/../../mk/install/install-info
FILES_SUBST+=		INFO_FILES=${INFO_FILES:Q}
FILES_SUBST+=		INSTALL_INFO=${INSTALL_INFO:Q}
FILES_SUBST+=		INFO_DIR=${INFO_DIR:Q}
.endif # INFO_FILES

.endif # TEXINFO_MK
