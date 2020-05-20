# $NetBSD: Makefile,v 1.5 2020/05/20 06:09:08 rillig Exp $

DISTNAME=	se-3.0.1
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://se-editor.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://se-editor.org/
COMMENT=	Screen oriented version of ed
LICENSE=	public-domain

GNU_CONFIGURE=	yes

# pat.c: In function 'amatch':
# pat.c:101:10: error: array subscript has type 'char' [-Werror=char-subscripts]
#     tagbeg[*(ppat + 1)] = lastc - lin;
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
