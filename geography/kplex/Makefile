# $NetBSD: Makefile,v 1.3 2016/04/29 08:49:45 plunky Exp $

DISTNAME=	kplex-1.3.2
CATEGORIES=	geography
MASTER_SITES=	http://www.stripydog.com/download/
EXTRACT_SUFX=	.tgz

HOMEPAGE=	http://www.stripydog.com/kplex/index.html
COMMENT=	Multitransport NMEA-0183 software data multiplexer
LICENSE=	gnu-gpl-v3

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Fixing path to config file
SUBST_FILES.paths=	README kplex.h kplex.conf.ex
SUBST_SED.paths=	-e "s|/etc/kplex.conf|${PKG_SYSCONFDIR}/kplex.conf|"

USE_TOOLS+=		gmake
BUILD_TARGET=		kplex

INSTALLATION_DIRS=	bin share/doc/kplex
CONF_FILES=		share/doc/kplex/kplex.conf.ex ${PKG_SYSCONFDIR}/kplex.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kplex ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/kplex
	${INSTALL_DATA} ${WRKSRC}/kplex.conf.ex ${DESTDIR}${PREFIX}/share/doc/kplex

.include "../../mk/bsd.pkg.mk"
