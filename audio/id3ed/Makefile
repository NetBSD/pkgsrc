# $NetBSD: Makefile,v 1.4 1999/07/13 01:20:11 jlam Exp $
#

DISTNAME=	id3ed-1.9
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/id3ed/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs.html

DEPENDS+=	readline-4.0:../../devel/readline

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ENV+=	LIBS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"

post-extract:
	${TOUCH} ${WRKSRC}/install.sh

.include "../../mk/bsd.pkg.mk"
