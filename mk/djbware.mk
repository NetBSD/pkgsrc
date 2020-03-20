# $NetBSD: djbware.mk,v 1.27 2020/03/20 19:40:39 rillig Exp $
#
# Makefile fragment for packages with djb-style build machinery
#
# Common functions provided:
# * a boilerplate RESTRICTED clause
# * typical defaults for BUILD_TARGET and INSTALL_TARGET
# * typical values for conf-* files
# * replace inline definitions of errno with "#include <errno.h>"
#
# TODO:
# * centralize handling of third-party manpages
# * centralize MASTER_SITES and SITES_foo
# * centralize compiler hack for arm{,32}
# * common install script for compatibility with default conf-home pathnames
# * PKG_OPTIONS (default):
#     djbware-errno-hack (off)
#     djbware-pathname-compat (on)
#     inet6 (off)
#     pam (off)
# * set RESTRICTED automatically iff patches or other mods are applied
# * be unrestricted by default for bulk builds
#

.if !defined(DJBWARE_MK)
DJBWARE_MK=		# defined

DJB_RESTRICTED?=	YES
DJB_MAKE_TARGETS?=	YES
DJB_BUILD_TARGETS?=	# empty
DJB_INSTALL_TARGETS?=	# empty
DJB_ERRNO_HACK?=	YES
DJB_SLASHPACKAGE?=	NO
.if !empty(DJB_SLASHPACKAGE:M[yY][eE][sS])
DJB_CONFIG_DIR?=	${WRKSRC}/src
DJB_BUILD_ARGS?=	# empty
.else
DJB_CONFIG_DIR?=	${WRKSRC}
.endif
DJB_CONFIG_PREFIX?=	${PREFIX}
DJB_CONFIG_HOME?=	conf-home
DJB_CONFIG_CMDS?=	${DO_NADA}

.if !empty(DJB_RESTRICTED:M[yY][eE][sS])
LICENSE=		djb-nonlicense

RESTRICTED=		modified source and binaries may not be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
.endif

.if !empty(DJB_MAKE_TARGETS:M[yY][eE][sS])
BUILD_TARGET?=		it ${DJB_BUILD_TARGETS}
INSTALL_TARGET?=	setup check ${DJB_INSTALL_TARGETS}
.endif

.if !defined(NO_CONFIGURE) && !target(do-configure)
do-configure:
	${RUN}cd ${DJB_CONFIG_DIR};		\
	for i in conf-*; do ${CP} $${i} $${i}.orig_dist; done;		\
	${ECHO} ${DESTDIR:Q}${DJB_CONFIG_PREFIX:Q} > conf-destdir;	\
	[ -f ${DJB_CONFIG_HOME} ] && \
		${ECHO} ${DJB_CONFIG_PREFIX} > ${DJB_CONFIG_HOME};	\
	[ -f conf-cc ] && \
		${ECHO} ${CC:Q} ${CFLAGS:Q} ${CPPFLAGS:Q} > conf-cc;	\
	[ -f conf-ld ] && \
		${ECHO} ${CC:Q} ${_STRIPFLAG_CC} ${LDFLAGS:Q} > conf-ld;\
	[ -f conf-bin ] && \
		${ECHO} ${DJB_CONFIG_PREFIX}/bin > conf-bin;		\
	[ -f conf-man ] && \
		${ECHO} ${DJB_CONFIG_PREFIX}/${PKGMANDIR} > conf-man;	\
	[ -f conf-qmail ] && \
		${ECHO} ${QMAILDIR} > conf-qmail;			\
	[ -f conf-bgincs ] && \
		${ECHO} ${PREFIX}/include > conf-bgincs;		\
	[ -f conf-bglibs ] && \
		${ECHO} ${PREFIX}/lib > conf-bglibs;			\
	${DJB_CONFIG_CMDS}
.endif

.if !target(do-build) && !empty(DJB_SLASHPACKAGE:M[yY][eE][sS])
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} package/compile ${DJB_BUILD_ARGS}
.endif

.if !empty(DJB_ERRNO_HACK:M[yY][eE][sS])
PKG_SUPPORTED_OPTIONS+=	djbware-errno-hack
PKG_SUGGESTED_OPTIONS+=	djbware-errno-hack

.include "bsd.fast.prefs.mk"

.if exists(${PKGDIR}/options.mk)
. include "${PKGDIR}/options.mk"
.else
# Note: This expression is the same as ${PKGBASE}, but the latter is
# not defined yet, so we cannot use it here.
PKG_OPTIONS_VAR=	PKG_OPTIONS.${PKGNAME:C/-[0-9].*//}
.include "bsd.options.mk"
.endif

.if !empty(PKG_OPTIONS:Mdjbware-errno-hack)
SUBST_CLASSES+=		djbware
SUBST_STAGE.djbware=	do-configure
SUBST_FILES.djbware+=	error.h
SUBST_SED.djbware=	-e 's|^extern\ int\ errno\;|\#include \<errno.h\>|'
SUBST_MESSAGE.djbware=	Correcting definition of errno.
.endif
.else
.sinclude "${PKGDIR}/options.mk"
.endif

.endif	# DJBWARE_MK
