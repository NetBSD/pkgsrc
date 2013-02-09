# $NetBSD: Makefile,v 1.7 2013/02/09 11:19:15 adam Exp $

PKGNAME=	${DISTNAME:C/-/91-fuzzystrmatch-/}
COMMENT=	PostgreSQL fuzzystrmatch contribution

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/fuzzystrmatch

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
