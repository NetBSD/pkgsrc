# $NetBSD: Makefile,v 1.3 2020/05/20 06:09:06 rillig Exp $

DISTNAME=	mcpp-2.7.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcpp/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/mcpp/files/mcpp/V.2.7.2/
COMMENT=	Portable C/C++ preprocessor
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-mcpplib

# eval.c: In function 'eval_if':
# eval.c:361:44: error: array subscript has type 'char' [-Werror=char-subscripts]
#                  , opname[ op], prec, opname[ opp->op], opp->prec, opp->skip);
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../mk/bsd.pkg.mk"
