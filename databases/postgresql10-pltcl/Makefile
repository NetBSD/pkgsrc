# $NetBSD: Makefile,v 1.22 2022/06/28 11:31:33 wiz Exp $

PKGNAME=	${DISTNAME:S/-/10-pltcl-/}
PKGREVISION=	1
COMMENT=	PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql10-server>=${PKGVERSION_NOREV}:../../databases/postgresql10-server

.include "../../databases/postgresql10/Makefile.common"

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/tcl

.include "../../databases/postgresql10-client/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
