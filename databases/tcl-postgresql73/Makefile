# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:24 tv Exp $

PKGNAME=		tcl-postgresql73-${BASE_VERS}
PKGREVISION=	1
COMMENT=		Tcl interface to PostgreSQL

USE_BUILDLINK3=		yes

.include "../postgresql73/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		${WRKSRC}/src/interfaces/libpgtcl
BUILD_DIRS+=		${WRKSRC}/src/bin/pgtclsh

post-install:
	${GTAR} zxCf ${PREFIX}/man ${WRKSRC}/doc/man.tar.gz		\
		`${SED} -e "s|#.*||" ${FILESDIR}/man.tcl`

.include "../postgresql73-lib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
