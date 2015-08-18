# $NetBSD: Makefile,v 1.36 2015/08/18 07:31:02 wiz Exp $
#

DISTNAME=	id3ed-1.10.4
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://users.dakotacom.net/~donut/programs/id3ed/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.dakotacom.net/~donut/programs/id3ed.html
COMMENT=	Edit id3 description tags in mpeg3 files

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

# uses rl_startup_hook
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
