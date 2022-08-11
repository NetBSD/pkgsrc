# $NetBSD: Makefile,v 1.41 2022/08/11 05:08:33 gutteridge Exp $

DISTNAME=	neverball-1.6.0
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://neverball.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://neverball.org/
COMMENT=	Puzzle/action game similar to Super Monkey Ball
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pax

USE_LANGUAGES=	c99

# Avoiding multiples patches...
BUILDLINK_FNAME_TRANSFORM.SDL+=		-e "s|/SDL/|/|g"
BUILDLINK_FNAME_TRANSFORM.SDL_ttf+=	-e "s|/SDL/|/|g"

MAKE_ENV+=	ENABLE_NLS=0

SHAREDIR=	${PREFIX}/share/${PKGBASE}

INSTALLATION_DIRS=	bin share/doc/${PKGBASE} share/${PKGBASE}

LDFLAGS.DragonFly=	-lX11 -lm
LDFLAGS.SunOS+=		-lX11 -lm

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/manual.txt \
	    ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_PROGRAM} ${WRKSRC}/neverball ${WRKSRC}/neverputt \
	    ${DESTDIR}${PREFIX}/bin
	for d in `${FIND} ${WRKSRC}/data -type d -print`; do \
	    ${CHMOD} ${PKGDIRMODE} $${d}; \
	done
	for f in `${FIND} ${WRKSRC}/data -type f -print`; do \
	    ${CHMOD} ${SHAREMODE} $${f}; \
	done
	cd ${WRKSRC} && ${PAX} -rwppm data ${DESTDIR}${SHAREDIR}

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
