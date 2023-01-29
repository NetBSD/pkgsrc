# $NetBSD: Makefile,v 1.5 2023/01/29 21:16:09 ryoon Exp $

DISTNAME=	einstein-puzzle-2.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jordan-evens/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jordan-evens/einstein-puzzle/
COMMENT=	Computer implementation of a puzzle invented by Albert Einstein
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++11
USE_TOOLS+=	gmake

MAKE_FLAGS+=		PREFIX=${PREFIX}

INSTALLATION_DIRS+=	libexec

post-build:
	${ECHO} '#!/bin/sh' > ${WRKDIR}/einstein.sh
	${ECHO} "cd ${PREFIX}/share/einstein/res && ${PREFIX}/libexec/einstein" >> ${WRKDIR}/einstein.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/einstein ${DESTDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/einstein.sh ${DESTDIR}${PREFIX}/bin/einstein

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
