# $NetBSD: Makefile,v 1.3 2013/02/06 23:22:00 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/92-fuzzystrmatch-/}
PKGREVISION=	2
COMMENT=	PostgreSQL fuzzystrmatch contribution

DEPENDS+=	postgresql92-server>=${PKGVERSION_NOREV}:../../databases/postgresql92-server

.include "../../databases/postgresql92/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/fuzzystrmatch

.include "../../databases/postgresql92-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
