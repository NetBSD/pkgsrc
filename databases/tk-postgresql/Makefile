# $NetBSD: Makefile,v 1.19 2004/03/17 15:45:49 minskim Exp $

PKGNAME=		tk-postgresql-${BASE_VERS}
PKGREVISION=		2
COMMENT=		Tk interface to PostgreSQL

USE_BUILDLINK3=		yes

.include "../postgresql/Makefile.common"

USE_X11=		yes
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tk
CONFIGURE_ARGS+=	--with-tclconfig=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tkconfig=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh
MAKE_ENV+=		INSTALLED_LIBPQ=1 INSTALLED_LIBPGTCL=1

BUILD_DIRS=		${WRKSRC}/src/bin/pgtclsh
ALL_TARGET=		pgtksh
INSTALL_TARGET=		install-tk

post-install:
	${GTAR} zxCf ${PREFIX}/man ${WRKSRC}/doc/man.tar.gz		\
		`${SED} -e "s|#.*||" ${FILESDIR}/man.tk`

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../databases/tcl-postgresql/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
