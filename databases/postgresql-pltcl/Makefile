# $NetBSD: Makefile,v 1.9 2004/01/20 14:11:50 jlam Exp $

PKGNAME=		postgresql-pltcl-${BASE_VERS}
PKGREVISION=		1
COMMENT=		PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=		postgresql-server>=${BASE_VERS}:../../databases/postgresql-server

USE_BUILDLINK2=		yes

.include "../postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${LOCALBASE}/bin/tclsh

BUILD_DIRS=		${WRKSRC}/src/pl/tcl

.include "../postgresql-lib/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
