# $NetBSD: Makefile,v 1.20 2016/09/15 14:32:41 wiz Exp $
#

DISTNAME=		libmatheval-1.1.8
PKGREVISION=		3
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GNU:=libmatheval/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/libmatheval/
COMMENT=		Library for evaluating mathematical expressions

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		flex
PTHREAD_OPTS+=		require
INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	libmatheval.pc.in
TEST_TARGET=		check

CONFIGURE_ENV+=		ac_cv_lib_lex="none needed"

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
