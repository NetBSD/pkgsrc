# $NetBSD: Makefile,v 1.16 2004/01/20 14:11:50 jlam Exp $

PKGNAME=		tcl-postgresql-${BASE_VERS}
PKGREVISION=		1
COMMENT=		Tcl interface to PostgreSQL

USE_BUILDLINK2=		yes

.include "../postgresql/Makefile.common"

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

.include "../postgresql-lib/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
