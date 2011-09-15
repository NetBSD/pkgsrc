# $NetBSD: Makefile,v 1.1.1.1 2011/09/15 08:32:22 adam Exp $

PKGNAME=	${DISTNAME:C/-/91-fuzzystrmatch-/}
COMMENT=	PostgreSQL fuzzystrmatch contribution

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/fuzzystrmatch

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
