# $NetBSD: Makefile,v 1.18 2004/01/22 07:15:00 grant Exp $
#

DISTNAME=	id3ed-1.10.4
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/programs/id3ed/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs/id3ed.html
COMMENT=	Edit id3 description tags in mpeg3 files

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_GCC_SHLIB=		YES

USE_GNU_READLINE=	# uses rl_startup_hook

LIBS+=			${LDFLAGS}

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
