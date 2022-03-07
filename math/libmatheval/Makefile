# $NetBSD: Makefile,v 1.26 2022/03/07 20:36:51 wiz Exp $

DISTNAME=		libmatheval-1.1.11
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GNU:=libmatheval/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/libmatheval/
COMMENT=		Library for evaluating mathematical expressions
LICENSE=		gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		flex
PTHREAD_OPTS+=		require
INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	libmatheval.pc.in
TEST_TARGET=		check

CONFIGURE_ENV+=		ac_cv_lib_lex="none needed"

# guile 2.0 fails with "matheval.c:33:2: error: #error Neither scm_num2dbl() nor SCM_NUM2DBL available"
# guile 2.2 fails
# Upstream has no bugtracker; reported via bug mailinglist 20220305.
.include "../../lang/guile18/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
