# $NetBSD: Makefile,v 1.20 2023/12/30 17:45:14 zafer Exp $
#

DISTNAME=	fortunes-de_0.20.orig
PKGNAME=	${DISTNAME:S/.orig$//:S/_/-/}
CATEGORIES=	games
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.debian.org/unstable/games/fortunes-de.html
COMMENT=	German data files for fortune

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

TOOL_DEPENDS+=	fortune-strfile-[0-9]*:../../games/fortune-strfile

STRFILE=		${LOCALBASE}/bin/strfile
INSTALLATION_DIRS=	share/games/fortune/de
CHECK_PORTABILITY_SKIP=	install.sh

USE_TOOLS+=		pax

do-build:
	find ${WRKSRC}/data -type f ! -name "*.dat" -exec ${STRFILE} {} \;

do-install:
	cd ${WRKSRC}/data && pax -rw . \
		${DESTDIR}${PREFIX}/share/games/fortune/de

.include "../../mk/bsd.pkg.mk"
