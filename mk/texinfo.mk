# $NetBSD: texinfo.mk,v 1.14.2.2 2003/08/14 07:37:04 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk when INFO_FILES is
# not empty or USE_MAKEINFO is not "no".
#

.if !defined(TEXINFO_MK)
TEXINFO_MK=	# defined

.if !empty(INFO_FILES)
#
# Handle install-info.
# 

# Use bsd.pkg.install.mk framework i.e. INSTALL/DEINSTALL scripts
# to handle install-info execution.
USE_PKGINSTALL=		YES

# Pathname relative to ${PREFIX} of directory holding the info
# files and the Info dir file.
INFO_DIR?=	info

# Does the system have the install-info command?
# Any version will fit (really?).
_INSTALL_INFO=
.  for _i_ in /usr/bin/install-info /sbin/install-info
.    if exists(${_i_})
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

# When not using buildlink2 set INSTALL_INFO in environment to ${TRUE}
# so the package build/install step does not register itself the info
# files as this is the job of the INSTALL script.
# This is far from being 100% robust but it is "Mostly Harmless"
# when it fails to catch some install-info invocations.
.if !empty(USE_BUILDLINK2:M[nN][oO])
CONFIGURE_ENV+=		INSTALL_INFO="${TRUE}"
MAKE_ENV+=		INSTALL_INFO="${TRUE}"
.endif

.if empty(USE_MAKEINFO:M[nN][oO])
#
# Handle makeinfo.
#

# Minimum required version for the GNU makeinfo command.
TEXINFO_REQD?=	3.12

# Argument to specify maximum info files size for newer versions
# of makeinfo. This argument is supported since makeinfo 4.1.
_MAKEINFO_SPLIT_SIZE_ARG+=	--split-size=50000

# The minimum version of makeinfo for which the default info files size
# was bumped from 50000.
_MAKEINFO_SPLIT_SIZE_VERSION=	4.6

# Add OPSYS specific flags if any.
MAKEINFO_ARGS+=         ${_OPSYS_MAKEINFO_ARGS}

# Does the system has a makeinfo command?
_MAKEINFO=
.  for _i_ in /usr/bin/makeinfo
.    if exists(${_i_})
_MAKEINFO=	${_i_}
.    endif
.  endfor

# Record makeinfo's version.
# If makeinfo's version contains useful information outside [0-9].[0-9],
# the following would have to be changed as well as the comparison below.
.  if !empty(_MAKEINFO) && !defined(MAKEINFO_VERSION)
MAKEINFO_VERSION_OUTPUT!=	${_MAKEINFO} --version 2>/dev/null || ${ECHO}
MAKEINFO_VERSION=
.    for _i_ in ${MAKEINFO_VERSION_OUTPUT:M[0-9]*.[0-9]*:C/[^0-9.]//}
.       if empty(MAKEINFO_VERSION)
MAKEINFO_VERSION=	${_i_}
.       endif
.    endfor
MAKEFLAGS+=			MAKEINFO_VERSION=${MAKEINFO_VERSION}
.  endif

# Sort out if the version provided by devel/gtexinfo is needed.
# If it is add it as build time dependency and set MAKEINFO
# to the makeinfo it provides.
# Here it is assumed devel/gtexinfo's makeinfo version will be
# superior or equal to TEXINFO_REQD.
_NEED_TEXINFO=		YES
.  if defined(MAKEINFO_VERSION) && ${MAKEINFO_VERSION} >= ${TEXINFO_REQD}
_NEED_TEXINFO=		NO
.  endif
.  if !empty(_NEED_TEXINFO:M[yY][eE][sS])
BUILD_DEPENDS+=		gtexinfo>=${TEXINFO_REQD}:../../devel/gtexinfo
_GTEXINFO_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		_GTEXINFO_PREFIX=gtexinfo
# assume devel/gtexinfo version is >= ${_MAKEINFO_SPLIT_SIZE_VERSION}
MAKEINFO_ARGS+=		${_MAKEINFO_SPLIT_SIZE_ARG}
MAKEINFO=		${_GTEXINFO_PREFIX}/bin/makeinfo ${MAKEINFO_ARGS}
.  else
.    if defined(MAKEINFO_VERSION) && ${MAKEINFO_VERSION} >= ${_MAKEINFO_SPLIT_SIZE_VERSION}
MAKEINFO_ARGS+=		${_MAKEINFO_SPLIT_SIZE_ARG}
.    endif
MAKEINFO=		${_MAKEINFO} ${MAKEINFO_ARGS}
.  endif

# When not using buildlink2 set MAKEINFO in environment to the pathname
# of the right makeinfo command.
.  if !empty(USE_BUILDLINK2:M[nN][oO])
CONFIGURE_ENV+=		MAKEINFO="${MAKEINFO}"
MAKE_ENV+=		MAKEINFO="${MAKEINFO}"
.  endif

.else # !USE_MAKEINFO
# When not using buildlink2 set MAKEINFO in environment to ${FALSE}
.  if !empty(USE_BUILDLINK2:M[nN][oO])
CONFIGURE_ENV+=		MAKEINFO="${FALSE}"
MAKE_ENV+=		MAKEINFO="${FALSE}"
.  endif
.endif # USE_MAKEINFO

.endif # TEXINFO_MK
