# $NetBSD: Makefile,v 1.25 2012/05/16 12:08:50 marino Exp $

DISTNAME=	neverball-1.5.4
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://neverball.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://neverball.org/
COMMENT=	Puzzle/action game similar to Super Monkey Ball

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pax

# Avoiding multiples patches...
BUILDLINK_FNAME_TRANSFORM.SDL+=	-e "s|/SDL/|/|g"
BUILDLINK_FNAME_TRANSFORM.SDL_ttf+=	-e "s|/SDL/|/|g"

MAKE_ENV+=	ENABLE_NLS=0

SHAREDIR=	${PREFIX}/share/${PKGBASE}

INSTALLATION_DIRS=	bin share/doc/${PKGBASE} share/${PKGBASE}

LDFLAGS.DragonFly=	-lX11 -lm

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/MANUAL ${WRKSRC}/README \
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
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
