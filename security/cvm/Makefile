# $NetBSD: Makefile,v 1.3 2005/08/30 03:57:11 schmonz Exp $
#

DISTNAME=		cvm-0.76
CATEGORIES=		security
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/cvm/
COMMENT=		Credential Validation Modules

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	qmail-init.c
SUBST_SED.paths=	-e 's|/var/qmail|${QMAILDIR}|g'
SUBST_MESSAGE.paths=	"Fixing paths."

USE_PKGINSTALL=		YES
RCD_SCRIPTS=		cvm
PKG_USERS+=		cvmlog:users::cvmlog

DJB_CONFIG_CMDS=							\
	${ECHO} ${DJB_CONFIG_PREFIX}/include > conf-include;		\
	${ECHO} ${DJB_CONFIG_PREFIX}/lib > conf-lib

.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
