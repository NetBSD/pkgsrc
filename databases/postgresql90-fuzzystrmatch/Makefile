# $NetBSD: Makefile,v 1.5 2012/07/01 19:42:06 morr Exp $

PKGNAME=	${DISTNAME:C/-/90-fuzzystrmatch-/}
COMMENT=	PostgreSQL fuzzystrmatch contribution

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

BUILD_DIRS=		contrib/fuzzystrmatch
BUILD_MAKE_FLAGS=	USE_PGXS=1

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
