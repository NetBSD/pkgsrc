# $NetBSD: Makefile,v 1.7 2005/12/05 20:50:01 rillig Exp $

PKGNAME=		tcl-postgresql73-${BASE_VERS}
PKGREVISION=	1
COMMENT=		Tcl interface to PostgreSQL


.include "../../databases/postgresql73/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH=${TCLSH:Q}
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh
MAKE_ENV+=		INSTALLED_LIBPQ=1
USE_TOOLS+=		gtar

BUILD_DIRS=		${WRKSRC}/src/port
BUILD_DIRS+=		${WRKSRC}/src/interfaces/libpgtcl
BUILD_DIRS+=		${WRKSRC}/src/bin/pgtclsh

post-install:
	${GTAR} zxCf ${PREFIX}/man ${WRKSRC}/doc/man.tar.gz		\
		`${SED} -e "s|#.*||" ${FILESDIR}/man.tcl`

.include "../../databases/postgresql73-lib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
