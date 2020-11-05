# $NetBSD: Makefile,v 1.2 2020/11/05 09:07:46 ryoon Exp $

PKGNAME=	${DISTNAME:S/-/13-pltcl-/}
PKGREVISION=	1
COMMENT=	PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql13-server>=${PKGVERSION_NOREV}:../../databases/postgresql13-server

.include "../../databases/postgresql13/Makefile.common"

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/tcl

.include "../../databases/postgresql13-client/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
