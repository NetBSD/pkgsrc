# $NetBSD: Makefile,v 1.9 2006/07/29 00:59:23 schmonz Exp $
#

DISTNAME=		cvm-0.80
CATEGORIES=		security
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/cvm/
COMMENT=		Credential Validation Modules

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

USE_LIBTOOL=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	qmail-init.c
SUBST_SED.paths=	-e 's|/var/qmail|${QMAILDIR}|g'
SUBST_MESSAGE.paths=	Fixing paths.

RCD_SCRIPTS=		cvm
PKG_GROUPS+=		cvmlog
PKG_USERS+=		cvmlog:cvmlog

DJB_CONFIG_CMDS=							\
	${ECHO} ${DJB_CONFIG_PREFIX}/include > conf-include;		\
	${ECHO} ${DJB_CONFIG_PREFIX}/lib > conf-lib

.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
