# $NetBSD: Makefile,v 1.15 2009/06/30 00:07:22 joerg Exp $
#

DISTNAME=		cvm-0.95
CATEGORIES=		security
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/cvm/
COMMENT=		Credential Validation Modules

MAKE_JOBS_SAFE=		no

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

USE_LIBTOOL=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	qmail-init.c
SUBST_SED.paths=	-e 's|/var/qmail|${QMAILDIR}|g'
SUBST_MESSAGE.paths=	Fixing paths.

SUBST_CLASSES+=		shlibs
SUBST_STAGE.shlibs=	do-configure
SUBST_FILES.shlibs=	INSTHIER
SUBST_SED.shlibs=	-e 's|@CVM_LIB_EXT@|${CVM_LIB_EXT}|g'
SUBST_MESSAGE.shlibs=	Fixing shlibs.

RCD_SCRIPTS=		cvm
PKG_GROUPS+=		cvmlog
PKG_USERS+=		cvmlog:cvmlog

BUILD_DEFS+=		QMAILDIR
PLIST_SUBST+=		CVM_LIB_EXT=${CVM_LIB_EXT:Q}

DJB_CONFIG_CMDS=							\
	${ECHO} ${DJB_CONFIG_PREFIX}/include > conf-include;		\
	${ECHO} ${DJB_CONFIG_PREFIX}/lib > conf-lib

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
CVM_LIB_EXT=dylib
.else
CVM_LIB_EXT=so
.endif


.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
