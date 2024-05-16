# $NetBSD: Makefile,v 1.30 2024/05/16 06:15:15 wiz Exp $

DISTNAME=		aiccu_20070115
PKGNAME=		${DISTNAME:S/_/-/:S/.//g}
PKGREVISION=		15
CATEGORIES=		net
MASTER_SITES=		http://www.sixxs.net/archive/sixxs/aiccu/unix/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.sixxs.net/tools/aiccu/
COMMENT=		Automatic IPv6 Connectivity Client Utility

USE_TOOLS+=		gmake
USE_FEATURES+=		inet6
CHECK_PORTABILITY_SKIP+= debian/*

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	pre-configure
SUBST_FILES.sysconfdir=	common/aiccu.h
SUBST_SED.sysconfdir=	-e 's,/etc/aiccu.conf,${PKG_SYSCONFDIR}/aiccu.conf,'

EXAMPLESDIR=		${PREFIX}/share/examples/aiccu
DOCDIR=			${PREFIX}/share/doc/aiccu
CONF_FILES=		${EXAMPLESDIR}/aiccu.conf ${PKG_SYSCONFDIR}/aiccu.conf
CONF_FILES_MODE=	0600

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1 share/examples/aiccu
INSTALLATION_DIRS+=	share/doc/aiccu

RCD_SCRIPTS=		aiccu

.include "options.mk"

# the distfile untars as ${WRKDIR}/aiccu/ but this would conflict with the
# rc.d script that gets copied to the same name ${WRKDIR}/${RCD_SCRIPTS}
post-extract:
	${MV} ${WRKDIR}/aiccu ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix-console/aiccu ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/doc/aiccu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/doc/aiccu.conf ${DESTDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/LICENSE ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/COPYRIGHT ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/HOWTO ${DESTDIR}${DOCDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
