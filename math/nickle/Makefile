# $NetBSD: Makefile,v 1.14 2013/07/15 02:02:25 ryoon Exp $

DISTNAME=	nickle-2.77
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

GNU_CONFIGURE=	yes

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

# lex.l:131:5: error: 'rl_catch_signals' undeclared (first use in this function)
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
