# $NetBSD: Makefile,v 1.3 2026/02/13 10:52:26 adam Exp $

PKGNAME=	${DISTNAME:S/-/18-pltcl-/}
COMMENT=	PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql18-server>=${PKGVERSION_NOREV}:../../databases/postgresql18-server

.include "../../databases/postgresql18/Makefile.common"

USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/tcl

.include "../../databases/postgresql18-client/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
