# $NetBSD: Makefile,v 1.19 2020/01/26 17:31:38 rillig Exp $

DISTNAME=	nickle-2.84
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

GNU_CONFIGURE=	yes

# suppress detection of DOCBOOK
CONFIGURE_ENV+=	ac_cv_path_DOCBOOK2PDF=

TEST_TARGET=	check

# rl_reset_after_signal, rl_echo_signal_char are missing in libedit as of 2018/12/02
#.include "../../mk/readline.buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
