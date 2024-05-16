# $NetBSD: Makefile,v 1.8 2024/05/16 06:14:55 wiz Exp $

DISTNAME=	ironwail-0.7.0
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=andrei-drexler/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/andre-drexler/ironwail
COMMENT=	High performance QuakeSpasm fork
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

NO_CONFIGURE=	yes

BUILD_DIRS=	Quake
BUILD_TARGET=	release

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/ironwail

post-extract:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/ironwail.template > ${WRKDIR}/ironwail

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ironwail ${DESTDIR}${PREFIX}/bin/ironwail
	${INSTALL_PROGRAM} ${WRKSRC}/Quake/ironwail ${DESTDIR}${PREFIX}/libexec/ironwail
	${INSTALL_DATA} ${WRKSRC}/Quake/ironwail.pak ${DESTDIR}${PREFIX}/share/ironwail/ironwail.pak

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
