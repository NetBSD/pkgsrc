# $NetBSD: Makefile,v 1.15 2003/01/10 17:53:06 salo Exp $
#

DISTNAME=	id3ed-1.10.4
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/programs/id3ed/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs/id3ed.html
COMMENT=	Edit id3 description tags in mpeg3 files

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES

USE_GNU_READLINE=	# uses rl_startup_hook

LIBS+=			${LDFLAGS}

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
