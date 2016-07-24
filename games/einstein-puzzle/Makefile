# $NetBSD: Makefile,v 1.1 2016/07/24 11:48:14 wiz Exp $

DISTNAME=	einstein-puzzle-2.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=lksj/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lksj/einstein-puzzle/
COMMENT=	Computer implementation of a puzzle invented by Albert Einstein
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++

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
