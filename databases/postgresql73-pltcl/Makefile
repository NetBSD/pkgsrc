# $NetBSD: Makefile,v 1.3 2004/10/10 17:46:07 jdolecek Exp $

PKGNAME=		postgresql73-pltcl-${BASE_VERS}
PKGREVISION=		# empty
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
