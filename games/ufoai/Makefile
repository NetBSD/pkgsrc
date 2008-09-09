# $NetBSD: Makefile,v 1.1.1.1 2008/09/09 12:46:36 kefren Exp $

DISTNAME=		ufoai-2.2.1
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufoai/}
CATEGORIES=		games

DISTFILES=	${DISTNAME}-source.tar.bz2
DISTFILES+=	${DISTNAME}-data.tar
DISTFILES+=	${DISTNAME}-mappack.tar.bz2

WRKSRC=		${WRKDIR}/${DISTNAME}-source

MAINTAINER=	pkgsrc-users@pkgsrc.org
COMMENT=	UFO Alien Invasion
HOMEPAGE=	http://ufoai.sourceforge.net/

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	tar gmake
MAKE_JOBS_SAFE=	no

do-extract:
	cd ${WRKDIR} && ${TAR} jxf ${DISTDIR}/${DISTNAME}-source.tar.bz2

post-build:
	cd ${WRKSRC} && ${GMAKE} lang # && ${GMAKE} maps

post-install:
	${TAR} xf ${DISTDIR}/${DISTNAME}-data.tar -C ${PREFIX}/share/ufoai
	${TAR} jxf ${DISTDIR}/${DISTNAME}-mappack.tar.bz2 -C ${PREFIX}/share/ufoai

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
