# $NetBSD: Makefile,v 1.1 2018/08/29 01:03:14 manu Exp $

PKGNAME=	${DISTNAME:C/-/96-fuzzystrmatch-/}
COMMENT=	PostgreSQL fuzzystrmatch contribution

DEPENDS+=	postgresql96-server>=${PKGVERSION_NOREV}:../../databases/postgresql96-server

.include "../../databases/postgresql96/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/fuzzystrmatch

.include "../../databases/postgresql96-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
