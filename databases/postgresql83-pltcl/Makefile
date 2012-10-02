# $NetBSD: Makefile,v 1.11 2012/10/02 21:25:42 asau Exp $

PKGNAME=	${DISTNAME:C/-/83-pltcl-/}
COMMENT=	PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql83-server>=${PKGVERSION_NOREV}:../../databases/postgresql83-server

.include "../../databases/postgresql83/Makefile.common"

CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh

BUILD_DIRS=		src/pl/tcl
BUILD_MAKE_FLAGS=	PGXS=1

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
