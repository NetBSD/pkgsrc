# $NetBSD: Makefile,v 1.3 1999/07/05 01:59:36 hubertf Exp $
#

DISTNAME=	id3ed-1.9
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/id3ed/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs.html

DEPENDS+=	readline-2.2:../../devel/readline

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ENV+=	LIBS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"

post-extract:
	${TOUCH} ${WRKSRC}/install.sh

.include "../../mk/bsd.pkg.mk"
