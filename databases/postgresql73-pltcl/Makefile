# $NetBSD: Makefile,v 1.1.1.1 2004/07/24 22:19:43 recht Exp $

PKGNAME=		postgresql73-pltcl-${BASE_VERS}
COMMENT=		PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql73-server>=${BASE_VERS}:../../databases/postgresql73-server

USE_BUILDLINK3=		yes

.include "../postgresql73/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${LOCALBASE}/bin/tclsh

BUILD_DIRS=		${WRKSRC}/src/pl/tcl

.include "../postgresql73-lib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
