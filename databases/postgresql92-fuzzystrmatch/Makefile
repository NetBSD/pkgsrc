# $NetBSD: Makefile,v 1.2 2012/12/16 01:52:08 obache Exp $

PKGNAME=	${DISTNAME:C/-/92-fuzzystrmatch-/}
PKGREVISION=	1
COMMENT=	PostgreSQL fuzzystrmatch contribution

DEPENDS+=	postgresql92-server>=${PKGVERSION_NOREV}:../../databases/postgresql92-server

.include "../../databases/postgresql92/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/fuzzystrmatch

.include "../../databases/postgresql92-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
