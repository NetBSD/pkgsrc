# $NetBSD: Makefile,v 1.2 2024/05/06 08:40:25 jperkin Exp $

PKGREVISION= 1
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Single-player dungeon exploration game (text-only version)

CONFLICTS+=	angband-tty-[0-9]*
CONFLICTS+=	angband-sdl-[0-9]*
CONFLICTS+=	angband-x11-[0-9]*
SUPERSEDES=	angband-tty-[0-9]*

RM_DIRS=	fonts icons sounds tiles

post-install:
.for dir in ${RM_DIRS}
	${RM} -rf ${DESTDIR}${PREFIX}/share/angband/${dir}
.endfor

.include "../../mk/bsd.pkg.mk"
