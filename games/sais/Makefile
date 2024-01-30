# $NetBSD: Makefile,v 1.4 2024/01/30 14:22:04 ryoon Exp $

DISTNAME=	sais-1.6.3
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=kuroneko/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kuroneko/sais/
COMMENT=	Strange Adventures in Infinite Space
LICENSE=	gnu-gpl-v3 AND cc-by-nc-v4.0-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_INSTALL_PREFIX=	${PREFIX}/libexec/sais

INSTALLATION_DIRS+=	bin

post-build:
	${ECHO} '#!/bin/sh' > ${WRKDIR}/strange
	${ECHO} 'cd ${PREFIX}/libexec/sais && ./strange' >> ${WRKDIR}/strange
	${CHMOD} 755 ${WRKDIR}/strange

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/strange ${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
