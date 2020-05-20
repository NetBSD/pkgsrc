# $NetBSD: Makefile,v 1.3 2020/05/20 06:09:09 rillig Exp $

DISTNAME=	veriwell-2.8.7
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=veriwell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/veriwell/
COMMENT=	Verilog Simulator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++03

TEST_TARGET=	check

# parse.yy:2253:57: error: array subscript has type 'char' [-Werror=char-subscripts]
# parse.yy:2253:85: error: array subscript has type 'char' [-Werror=char-subscripts]
#                 $$ = edge_mask[$1[0]][$1[1]];
# parse.yy:2258:79: error: array subscript has type 'char' [-Werror=char-subscripts]
# parse.yy:2258:108: error: array subscript has type 'char' [-Werror=char-subscripts]
#                 $$ = $3 | edge_mask[$1[0]][$1[1]];
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
