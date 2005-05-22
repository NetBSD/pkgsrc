# $NetBSD: Makefile,v 1.24 2005/05/22 20:07:38 jlam Exp $
#

DISTNAME=	id3ed-1.10.4
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/programs/id3ed/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs/id3ed.html
COMMENT=	Edit id3 description tags in mpeg3 files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

USE_GNU_READLINE=	# uses rl_startup_hook

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
