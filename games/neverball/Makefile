# $NetBSD: Makefile,v 1.3 2004/10/03 00:14:46 tv Exp $
#

DISTNAME=	neverball-1.2.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.icculus.org/neverball/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.icculus.org/neverball/
COMMENT=	Part puzzle game, part action game and with SDL graphics

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes

# Avoiding multiples patches...
BUILDLINK_TRANSFORM.SDL+=	-e "s|/SDL/|/|g"
BUILDLINK_TRANSFORM.SDL_ttf+=	-e "s|/SDL/|/|g"

SHAREDIR=	${PREFIX}/share/${PKGBASE}

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
