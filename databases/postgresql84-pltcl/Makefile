# $NetBSD: Makefile,v 1.6.2.1 2012/07/03 19:58:22 tron Exp $

PKGNAME=	${DISTNAME:C/-/84-pltcl-/}
COMMENT=	PL/Tcl procedural language for the PostgreSQL backend

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql84-server>=${PKGVERSION_NOREV}:../../databases/postgresql84-server

.include "../../databases/postgresql84/Makefile.common"

CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh

BUILD_DIRS=		src/pl/tcl
BUILD_MAKE_FLAGS=	PGXS=1

.include "../../databases/postgresql84-client/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
