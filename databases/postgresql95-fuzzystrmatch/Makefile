# $NetBSD: Makefile,v 1.1 2016/02/25 21:37:36 tnn Exp $

PKGNAME=	${DISTNAME:C/-/95-fuzzystrmatch-/}
COMMENT=	PostgreSQL fuzzystrmatch contribution

DEPENDS+=	postgresql95-server>=${PKGVERSION_NOREV}:../../databases/postgresql95-server

.include "../../databases/postgresql95/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/fuzzystrmatch

.include "../../databases/postgresql95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
