# $NetBSD: Makefile,v 1.73 2022/06/28 11:33:56 wiz Exp $

DISTNAME=	puzzles-20220127
GIT_COMMIT=	c43a34fbfe430d235bafc379595761880a19ed9f
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	-https://git.tartarus.org/?p=simon/puzzles.git;a=snapshot;h=${GIT_COMMIT};sf=tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/puzzles/
COMMENT=	Collection of small one-player puzzle games by Simon Tatham
LICENSE=	mit

BUILD_DEPENDS+=		halibut>=1.1:../../textproc/halibut
BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick

WRKSRC=		${WRKDIR}/puzzles-${GIT_COMMIT:C,(.......).*,\1,}
AUTO_MKDIRS=	yes

USE_LANGUAGES=		c99
USE_CMAKE=		yes
USE_TOOLS+=		perl pkg-config

SUBST_CLASSES+=		net
SUBST_STAGE.net=	pre-configure
SUBST_FILES.net=	CMakeLists.txt
SUBST_SED.net=		-e 's,puzzle(net$$,&game,'

pre-configure:
	cd ${WRKSRC} && make -f Makefile.doc puzzles.txt
	cd ${WRKSRC} && mv net.c netgame.c && mv icons/net.sav icons/netgame.sav

post-install:
	${INSTALL_DATA} ${WRKSRC}/puzzles.txt \
		${DESTDIR}${PREFIX}/share/doc/puzzles

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
