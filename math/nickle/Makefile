# $NetBSD: Makefile,v 1.11 2013/05/26 20:14:48 wiz Exp $

DISTNAME=	nickle-2.77
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

GNU_CONFIGURE=	yes

TEST_TARGET=	check

USE_GNU_READLINE=	yes
# as of nickle-2.77 on NetBSD-6.99.20/amd64:
# lex.l: In function 'LexInit':
# lex.l:129:27: warning: assignment from incompatible pointer type
# lex.l:131:5: error: 'rl_catch_signals' undeclared (first use in this function)
# lex.l:131:5: note: each undeclared identifier is reported only once for each function it appears in

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
