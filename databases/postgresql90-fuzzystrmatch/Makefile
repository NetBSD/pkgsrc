# $NetBSD: Makefile,v 1.7 2012/12/16 01:52:05 obache Exp $

PKGNAME=	${DISTNAME:C/-/90-fuzzystrmatch-/}
PKGREVISION=	1
COMMENT=	PostgreSQL fuzzystrmatch contribution

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS=		contrib/fuzzystrmatch
BUILD_MAKE_FLAGS=	USE_PGXS=1

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
