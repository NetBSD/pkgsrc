# $NetBSD: Makefile,v 1.17 2004/01/20 14:11:50 jlam Exp $

PKGNAME=		tk-postgresql-${BASE_VERS}
PKGREVISION=		1
COMMENT=		Tk interface to PostgreSQL

USE_BUILDLINK2=		yes

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

.include "../postgresql-lib/buildlink2.mk"
.include "../tcl-postgresql/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
