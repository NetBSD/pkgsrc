# $NetBSD: Makefile,v 1.64 2019/08/11 13:21:04 wiz Exp $

DISTNAME=	puzzles-20181212
GIT_COMMIT=	ced51ada363d895eee796dd03923042f97f95321
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	-https://git.tartarus.org/?p=simon/puzzles.git;a=snapshot;h=${GIT_COMMIT};sf=tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/puzzles/
COMMENT=	Collection of small one-player puzzle games by Simon Tatham
LICENSE=	mit

WRKSRC=		${WRKDIR}/puzzles-${GIT_COMMIT:C,(.......).*,\1,}
USE_TOOLS+=	gmake pkg-config perl autoreconf autoconf automake
AUTO_MKDIRS=	yes

BUILD_DEPENDS+=		halibut>=1.1:../../textproc/halibut

USE_LANGUAGES=		c99
GNU_CONFIGURE=		yes
BUILDLINK_TRANSFORM+=	rm:-Werror
MAKE_FLAGS=		prefix=${PREFIX}
MAKE_FLAGS+=		gamesdir=${PREFIX}/bin
CFLAGS+=		-DREVISION=${DISTNAME:S/puzzles-//}

pre-configure:
	cd ${WRKSRC} && perl mkfiles.pl
	cd ${WRKSRC} && ${SH} mkauto.sh
	cd ${WRKSRC} && gmake -f Makefile.doc puzzles.txt

post-install:
	${INSTALL_DATA} ${WRKSRC}/puzzles.txt \
		${DESTDIR}${PREFIX}/share/doc/puzzles

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
