# $NetBSD: Makefile,v 1.16 2012/09/13 17:14:36 drochner Exp $
#

DISTNAME=		libmatheval-1.1.8
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GNU:=libmatheval/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/libmatheval/
COMMENT=		Library for evaluating mathematical expressions

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		require
INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	libmatheval.pc.in
TEST_TARGET=		check

.include "../../devel/flex/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
