# $NetBSD: Makefile,v 1.28 2012/09/11 20:32:13 asau Exp $

DISTNAME=	nut-15.8
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nut/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nut.sourceforge.net/
COMMENT=	Record what you eat and analyze your meals
LICENSE=	gnu-gpl-v2

BUILD_TARGET=	nut
USE_TOOLS+=	gmake

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_FILES.path=	Makefile
SUBST_SED.path=		-e 's|/usr/local/lib|${PREFIX}/share|g'

INSTALLATION_DIRS=	bin share/doc/nut share/nut

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nut ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/raw.data/* ${DESTDIR}${PREFIX}/share/nut
	${INSTALL_DATA} ${WRKSRC}/nut.html ${DESTDIR}${PREFIX}/share/doc/nut

.include "../../mk/bsd.pkg.mk"
