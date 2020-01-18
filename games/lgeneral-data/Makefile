# $NetBSD: Makefile,v 1.11 2020/01/18 23:32:03 rillig Exp $
#

DISTNAME=	lgeneral-data-1.1.3
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgeneral/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lgames.sourceforge.net/index.php?project=LGeneral
COMMENT=	Panzer General data files for lgeneral

DEPENDS+=	lgeneral>=1.1.1:../../games/lgeneral

GNU_CONFIGURE=	YES

INSTALLATION_DIRS+=	share/games/lgeneral/nations \
			share/games/lgeneral/gfx/flags \
			share/games/lgeneral/gfx/units \
			share/games/lgeneral/units

.include "../../mk/bsd.pkg.mk"
