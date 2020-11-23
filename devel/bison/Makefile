# $NetBSD: Makefile,v 1.118 2020/11/23 13:55:13 wiz Exp $

DISTNAME=	bison-3.7.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=bison/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/bison/bison.html
COMMENT=	GNU yacc(1) replacement
LICENSE=	gnu-gpl-v3

CHECK_PORTABILITY_SKIP+=	tests/local.mk

USE_LANGUAGES=		c c++
USE_TOOLS+=		grep gm4:run flex perl:build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-yacc
CONFIGURE_ENV+=		ac_cv_prog_M4=${TOOLS_PATH.gm4}

.include "options.mk"

INFO_FILES=		yes
TEST_TARGET=		check
REPLACE_PERL+=		examples/extexi
REPLACE_SH+=		examples/test examples/*/*.test

CONFIGURE_ARGS.Cygwin+=	ac_cv_func___fpending=yes

# Avoid rebuilding manpage
pre-build:
	${TOUCH} ${WRKSRC}/doc/bison.1

.include "../../mk/bsd.pkg.mk"
