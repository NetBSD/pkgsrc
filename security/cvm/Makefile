# $NetBSD: Makefile,v 1.1.1.1 2005/07/20 03:28:41 schmonz Exp $
#

DISTNAME=		cvm-0.71
CATEGORIES=		security
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/cvm/
COMMENT=		Credential Validation Modules

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

BUILD_TARGET=		all instshow installer instcheck

DJB_RESTRICTED=		NO
BGWARE_INSTALLER=	YES

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	qmail-init.c
SUBST_SED.paths=	-e 's|/var/qmail|${QMAILDIR}|g'
SUBST_MESSAGE.paths=	"Fixing paths."

USE_PKGINSTALL=		YES
RCD_SCRIPTS=		cvm
PKG_USERS+=		cvmlog:users::cvmlog

DJB_CONFIG_CMDS=							\
	${ECHO} ${LOCALBASE}/include > conf-include;			\
	${ECHO} ${LOCALBASE}/lib > conf-lib

.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
