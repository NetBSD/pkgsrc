# $NetBSD: Makefile,v 1.2 2023/05/06 19:09:21 ryoon Exp $

DISTNAME=	ironwail-0.6.0
PKGREVISION=	1
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

post-extract:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/ironwail.template > ${WRKDIR}/ironwail

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ironwail ${DESTDIR}${PREFIX}/bin/ironwail

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
