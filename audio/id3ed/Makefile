# $NetBSD: Makefile,v 1.6 2000/11/05 02:48:06 hubertf Exp $
#

DISTNAME=	id3ed-1.10.2
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/programs/id3ed/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.azstarnet.com/~donut/programs/index.html

DEPENDS+=	readline>=4.0:../../devel/readline

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ENV+=	LIBS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"

post-extract:
	${TOUCH} ${WRKSRC}/install.sh

.include "../../mk/bsd.pkg.mk"
