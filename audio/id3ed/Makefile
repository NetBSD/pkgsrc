# $NetBSD: Makefile,v 1.14 2002/10/25 18:22:53 wiz Exp $
#

DISTNAME=	id3ed-1.10.2
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/programs/id3ed/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs/index.html
COMMENT=	Edit id3 description tags in mpeg3 files

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES

USE_GNU_READLINE=	# uses rl_startup_hook

LIBS+=			${LDFLAGS}

post-extract:
	${TOUCH} ${WRKSRC}/install.sh

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
