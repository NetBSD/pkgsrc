# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:55 jlam Exp $
#

DISTNAME=	neverball-1.2.2
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.icculus.org/neverball/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.icculus.org/neverball/
COMMENT=	Part puzzle game, part action game and with SDL graphics

USE_TOOLS+=	gmake

# Avoiding multiples patches...
BUILDLINK_TRANSFORM.SDL+=	-e "s|/SDL/|/|g"
BUILDLINK_TRANSFORM.SDL_ttf+=	-e "s|/SDL/|/|g"

SHAREDIR=	${PREFIX}/share/${PKGBASE}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/MAPPING \
	    ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_PROGRAM} ${WRKSRC}/neverball ${WRKSRC}/neverputt ${SHAREDIR}
	cd ${WRKSRC} && ${PAX} -rwppm data ${SHAREDIR}
	${SED} -e "s,@SHAREDIR@,${SHAREDIR},g" ${FILESDIR}/neverball.sh \
	    > ${WRKSRC}/neverball.sh
	${INSTALL_SCRIPT} ${WRKSRC}/neverball.sh ${PREFIX}/bin/neverball

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
