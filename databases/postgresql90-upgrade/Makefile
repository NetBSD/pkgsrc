# $NetBSD: Makefile,v 1.9 2013/02/06 23:21:58 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/90-upgrade-/}
PKGREVISION=	2
COMMENT=	PostgreSQL binary upgrade tool
MAINTAINER=	pkgsrc-users@NetBSD.org

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS+=		contrib/pg_upgrade
BUILD_DIRS+=		contrib/pg_upgrade_support

LIBS.SunOS+=	-lintl

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
