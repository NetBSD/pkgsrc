# $NetBSD: Makefile,v 1.25 2005/10/16 15:17:55 wiz Exp $
#

DISTNAME=	id3ed-1.10.4
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.dakotacom.net/~donut/programs/id3ed/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dakotacom.net/~donut/programs/id3ed.html
COMMENT=	Edit id3 description tags in mpeg3 files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

USE_GNU_READLINE=	# uses rl_startup_hook

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
