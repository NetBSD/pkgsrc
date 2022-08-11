# $NetBSD: Makefile,v 1.25 2022/08/11 05:08:23 gutteridge Exp $
DISTNAME=		REminiscence-0.4.9
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		http://cyxdown.free.fr/reminiscence/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		stb_vorbis.c
SITES.stb_vorbis.c=	${MASTER_SITE_GITHUB:=nothings/}stb/raw/1ee679ca2ef753a528db5ba6801e1067b40481b8/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cyxdown.free.fr/reminiscence/
COMMENT=		Engine to play Flashback by Delphine Software
LICENSE=		gnu-gpl-v3 AND public-domain

USE_LANGUAGES=		c++

BUILD_TARGET=		rs

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/REminiscence

pre-build:
	${CP} ${WRKDIR}/stb_vorbis.c ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rs ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/reminiscence.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${PREFIX}/share/doc/REminiscence

.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/tremor/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
