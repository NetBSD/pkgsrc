# $NetBSD: Makefile,v 1.16 2004/06/26 13:32:45 darcy Exp $

PKGNAME=		postgresql-pltcl-${BASE_VERS}
COMMENT=		PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=		postgresql-server>=${BASE_VERS}:../../databases/postgresql-server

USE_BUILDLINK3=		yes

.include "../postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${LOCALBASE}/bin/tclsh

BUILD_DIRS=		${WRKSRC}/src/pl/tcl

.include "../postgresql-lib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
