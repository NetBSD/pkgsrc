# $NetBSD: Makefile,v 1.34 2024/01/14 08:41:57 wiz Exp $

DISTNAME=	nickle-2.97
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.editlinereadline}
CONFIGURE_ARGS+=	CC_FOR_BUILD=${NATIVE_CC:Q:U${CC:Q}}

# suppress detection of DOCBOOK
CONFIGURE_ENV+=	ac_cv_path_DOCBOOK2PDF=

TEST_TARGET=	check

REPLACE_SH+=	bench/runbench.sh

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
