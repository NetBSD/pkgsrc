# $NetBSD: Makefile,v 1.14 2004/06/22 18:43:15 drochner Exp $

PKGNAME=		postgresql-pltcl-${BASE_VERS}
PKGREVISION=		4
COMMENT=		PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=		postgresql-server>=${BASE_VERS}:../../databases/postgresql-server

USE_BUILDLINK3=		yes

.include "../postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tclnt}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${LOCALBASE}/bin/tclsh

BUILD_DIRS=		${WRKSRC}/src/pl/tcl

.include "../postgresql-lib/buildlink3.mk"
.include "../../lang/libtcl-nothread/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
