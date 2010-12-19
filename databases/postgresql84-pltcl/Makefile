# $NetBSD: Makefile,v 1.4 2010/12/19 09:53:42 adam Exp $

PKGNAME=	${DISTNAME:C/-/84-pltcl-/}
COMMENT=	PL/Tcl procedural language for the PostgreSQL backend

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql84-server>=${PKGVERSION}:../../databases/postgresql84-server

.include "../../databases/postgresql84/Makefile.common"

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh

BUILD_DIRS=		src/pl/tcl

.include "../../databases/postgresql84-client/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
