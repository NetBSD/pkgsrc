# $NetBSD: Makefile,v 1.13 2013/05/30 16:58:01 wiz Exp $

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

.if (${OPSYS} == NetBSD) && empty(OS_VERSION:M6.99.2[1-9]*) && empty(OS_VERSION:M6.99.[345679][0-9]*) && empty(OS_VERSION:M[789].*) || (${OPSYS} == "DragonFly")
# lex.l:131:5: error: 'rl_catch_signals' undeclared (first use in this function)
USE_GNU_READLINE=	yes
.endif

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
