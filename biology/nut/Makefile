# $NetBSD: Makefile,v 1.25 2008/01/30 05:43:55 obache Exp $

DISTNAME=	nut-13.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nut/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nut.sourceforge.net/
COMMENT=	Record what you eat and analyze your meals

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	nut
USE_TOOLS+=	gmake

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_FILES.path=	Makefile
SUBST_SED.path=		-e 's|/usr/local/lib|${PREFIX}/share|g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nut ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/nut
	${INSTALL_DATA} ${WRKSRC}/raw.data/* ${DESTDIR}${PREFIX}/share/nut
	${INSTALL_MAN} ${WRKSRC}/nut.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
