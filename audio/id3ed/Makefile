# $NetBSD: Makefile,v 1.17 2003/10/29 16:31:46 gavan Exp $
#

DISTNAME=	id3ed-1.10.4
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/programs/id3ed/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs/id3ed.html
COMMENT=	Edit id3 description tags in mpeg3 files

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_GCC_SHLIB=		YES

USE_GNU_READLINE=	# uses rl_startup_hook

LIBS+=			${LDFLAGS}

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
