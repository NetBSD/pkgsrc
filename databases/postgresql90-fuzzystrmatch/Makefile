# $NetBSD: Makefile,v 1.8 2013/02/06 23:21:57 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/90-fuzzystrmatch-/}
PKGREVISION=	2
COMMENT=	PostgreSQL fuzzystrmatch contribution

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS=		contrib/fuzzystrmatch
BUILD_MAKE_FLAGS=	USE_PGXS=1

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
