# $NetBSD: Makefile,v 1.11 2001/06/11 02:05:07 jlam Exp $
#

DISTNAME=	id3ed-1.10.2
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/programs/id3ed/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs/index.html
COMMENT=	Edit id3 description tags in mpeg3 files

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

USE_GNU_READLINE=	# uses rl_startup_hook

.include "../../devel/readline/buildlink.mk"

CONFIGURE_ENV+=	LIBS="${LIBS}"
LIBS+=		${LDFLAGS}

post-extract:
	${TOUCH} ${WRKSRC}/install.sh

.include "../../mk/bsd.pkg.mk"
