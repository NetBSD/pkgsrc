# $NetBSD: Makefile,v 1.32 2012/09/12 00:24:39 asau Exp $
#

DISTNAME=	id3ed-1.10.4
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://users.dakotacom.net/~donut/programs/id3ed/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.dakotacom.net/~donut/programs/id3ed.html
COMMENT=	Edit id3 description tags in mpeg3 files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

# uses rl_startup_hook
USE_GNU_READLINE=	yes

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
