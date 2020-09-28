# $NetBSD: Makefile,v 1.7 2020/09/28 11:07:51 micha Exp $

DISTNAME=	shareware_doom_iwad
PKGNAME=	doom1-1.9
CATEGORIES=	games
MASTER_SITES=	http://www.doomworld.com/3ddownloads/ports/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
# The SHA1 hash listed here was checked while generating pkgsrc distinfo
HOMEPAGE=	https://doomwiki.org/wiki/DOOM1.WAD
COMMENT=	Shareware levels for Doom
LICENSE=	doom1-iwad-shareware-license

CONFLICTS+=	xdoom<1.10nb4

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	share/doom

NO_BUILD=		YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/DOOM1.WAD \
		${DESTDIR}${PREFIX}/share/doom/doom1.wad

.include "../../mk/bsd.pkg.mk"
