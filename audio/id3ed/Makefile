# $NetBSD: Makefile,v 1.21 2004/11/13 22:04:52 jlam Exp $
#

DISTNAME=	id3ed-1.10.4
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/programs/id3ed/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs/id3ed.html
COMMENT=	Edit id3 description tags in mpeg3 files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

USE_GNU_READLINE=	# uses rl_startup_hook

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
