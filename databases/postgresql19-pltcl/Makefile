# $NetBSD: Makefile,v 1.1 2026/11/24 19:22:52 adam Exp $

PKGNAME=	${DISTNAME:S/-/19-pltcl-/}
COMMENT=	PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql19-server>=${PKGVERSION_NOREV}:../../databases/postgresql19-server

.include "../../databases/postgresql19/Makefile.common"

USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/tcl

.include "../../databases/postgresql19-client/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
