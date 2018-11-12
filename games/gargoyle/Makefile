# $NetBSD: Makefile,v 1.5 2018/11/12 03:52:04 ryoon Exp $

DISTNAME=	gargoyle-2011.1
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=garglk/}
GITHUB_PROJECT=	garglk
GITHUB_TAG=	stable-${PKGVERSION_NOREV}

MAINTAINER=	wes.frazier@members.fsf.org
HOMEPAGE=	http://ccxvii.net/gargoyle/
COMMENT=	Graphical player for Interactive Fiction games
#LICENSE=	gnu-gpl-v2 AND mit AND original-bsd AND artistic-? AND some font licenses

WRKSRC=		${WRKDIR}/garglk-stable-2011.1

BUILD_DEPENDS+=	jam-[0-9]*:../../devel/jam

USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

INSTALLATION_DIRS=	bin libexec/gargoyle

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} jam

do-install:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} jam install && \
		${INSTALL_PROGRAM} ${WRKSRC}/build/dist/* ${DESTDIR}${PREFIX}/libexec/gargoyle && \
		ln -s -f ${DESTDIR}${PREFIX}/libexec/gargoyle/gargoyle ${DESTDIR}${PREFIX}/bin/gargoyle

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
