# $NetBSD: Makefile,v 1.29 2024/05/29 16:31:47 adam Exp $

PKGNAME=	${DISTNAME:S/-/12-pltcl-/}
PKGREVISION=	1
COMMENT=	PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql12-server>=${PKGVERSION_NOREV}:../../databases/postgresql12-server

.include "../../databases/postgresql12/Makefile.common"

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/tcl

.include "../../databases/postgresql12-client/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
