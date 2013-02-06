# $NetBSD: Makefile,v 1.6 2013/02/06 23:21:59 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/91-fuzzystrmatch-/}
PKGREVISION=	2
COMMENT=	PostgreSQL fuzzystrmatch contribution

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/fuzzystrmatch

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
