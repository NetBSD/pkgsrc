# $NetBSD: Makefile,v 1.28 2007/02/22 19:01:13 wiz Exp $
#

DISTNAME=	id3ed-1.10.4
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.dakotacom.net/~donut/programs/id3ed/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dakotacom.net/~donut/programs/id3ed.html
COMMENT=	Edit id3 description tags in mpeg3 files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

# uses rl_startup_hook
USE_GNU_READLINE=	yes

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
