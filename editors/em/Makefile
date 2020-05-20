# $NetBSD: Makefile,v 1.3 2020/05/20 06:09:03 rillig Exp $

DISTNAME=	em-1.0.0
CATEGORIES=	editors
MASTER_SITES=	http://pgas.freeshell.org/C/em/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://www.coulouris.net/cs_history/em_story/
COMMENT=	Early V6 Unix line-based editor for mortals
LICENSE=	public-domain

GNU_CONFIGURE=	yes
AUTO_MKDIRS=	yes

# em1.c: In function 'advance':
# em1.c:1554:11: error: array subscript has type 'char' [-Werror=char-subscripts]
#    braslist[*ep++] = lp;
#            ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../mk/bsd.pkg.mk"
