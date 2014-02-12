# $NetBSD: Makefile,v 1.8 2014/02/12 23:17:42 tron Exp $

PKGNAME=	${DISTNAME:C/-/91-fuzzystrmatch-/}
PKGREVISION=	1
COMMENT=	PostgreSQL fuzzystrmatch contribution

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/fuzzystrmatch

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
