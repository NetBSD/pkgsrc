# $NetBSD: Makefile,v 1.5 2006/06/13 18:06:21 ghen Exp $

DISTNAME=		aiccu_2005.01.31
PKGNAME=		${DISTNAME:S/_/-/:S/.//g}
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.sixxs.net/archive/sixxs/aiccu/unix/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.sixxs.net/tools/aiccu/
COMMENT=		Automatic IPv6 Connectivity Client Utility

BUILD_DIRS=		unix-console

USE_TOOLS+=		gmake

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	post-patch
SUBST_FILES.sysconfdir=	common/aiccu.h
SUBST_SED.sysconfdir=	-e 's,/etc/aiccu.conf,${PKG_SYSCONFDIR}/aiccu.conf,'

EXAMPLESDIR=		${PREFIX}/share/examples/aiccu
DOCDIR=			${PREFIX}/share/doc/aiccu
CONF_FILES=		${EXAMPLESDIR}/aiccu.conf ${PKG_SYSCONFDIR}/aiccu.conf
CONF_FILES_MODE=	0600

RCD_SCRIPTS=		aiccu

# the distfile untars as ${WRKDIR}/aiccu/ but this would conflict with the
# rc.d script that gets copied to the same name ${WRKDIR}/${RCD_SCRIPTS}
post-extract:
	${MV} ${WRKDIR}/aiccu ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix-console/aiccu ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/doc/aiccu.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/aiccu.conf ${EXAMPLESDIR}/
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/LICENSE ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/HOWTO ${DOCDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
