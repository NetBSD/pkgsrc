# $NetBSD: Makefile,v 1.3 2012/07/01 19:49:25 morr Exp $

PKGNAME=	${DISTNAME:C/-/91-fuzzystrmatch-/}
COMMENT=	PostgreSQL fuzzystrmatch contribution

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/fuzzystrmatch

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
