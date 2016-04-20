# $NetBSD: Makefile,v 1.37 2016/04/20 12:10:27 nros Exp $
#

DISTNAME=	id3ed-1.10.4
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://users.dakotacom.net/~donut/programs/id3ed/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.dakotacom.net/~donut/programs/id3ed.html
COMMENT=	Edit id3 description tags in mpeg3 files
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

# uses rl_startup_hook
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
