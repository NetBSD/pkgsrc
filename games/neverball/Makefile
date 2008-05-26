# $NetBSD: Makefile,v 1.17 2008/05/26 02:13:19 joerg Exp $
#

DISTNAME=	neverball-1.4.0
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.icculus.org/neverball/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.icculus.org/neverball/
COMMENT=	Part puzzle game, part action game and with SDL graphics

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pax

# Avoiding multiples patches...
BUILDLINK_FNAME_TRANSFORM.SDL+=	-e "s|/SDL/|/|g"
BUILDLINK_FNAME_TRANSFORM.SDL_ttf+=	-e "s|/SDL/|/|g"

SHAREDIR=	${PREFIX}/share/${PKGBASE}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README \
	    ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_PROGRAM} ${WRKSRC}/neverball ${WRKSRC}/neverputt \
	    ${DESTDIR}${SHAREDIR}
	cd ${WRKSRC} && pax -rwppm data ${DESTDIR}${SHAREDIR}
	${SED} -e "s,@SHAREDIR@,${SHAREDIR},g" ${FILESDIR}/neverball.sh \
	    > ${WRKSRC}/neverball.sh
	${INSTALL_SCRIPT} ${WRKSRC}/neverball.sh \
	    ${DESTDIR}${PREFIX}/bin/neverball

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
