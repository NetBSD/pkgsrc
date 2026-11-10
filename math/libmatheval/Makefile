# $NetBSD: Makefile,v 1.28 2026/11/10 15:43:51 wiz Exp $

DISTNAME=		libmatheval-1.1.12
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GNU:=libmatheval/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/libmatheval/
COMMENT=		Library for evaluating mathematical expressions
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		flex pkg-config
PTHREAD_OPTS+=		require
INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	libmatheval.pc.in
# as of 1.1.12:
# 1 failed unexpectedly.
TEST_TARGET=		check

CONFIGURE_ENV+=		ac_cv_lib_lex="none needed"

# to avoid xmalloc from the test suite polluting the name space
CFLAGS+=		-fvisibility=hidden

.include "../../lang/guile30/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
