# $NetBSD: Makefile,v 1.8 2001/06/21 21:40:09 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		tcl-postgresql-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		Tcl interface to PostgreSQL

USE_BUILDLINK_ONLY=	# defined
POSTGRESQL_LIB_REQD=	${PG_BASE_VERS}

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../lang/tcl/buildlink.mk"

MAKE_ENV+=		INSTALLED_LIBPQ=1

CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_DIR}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${LOCALBASE}/bin/tclsh

DIRS_TO_BUILD=		src/interfaces/libpgtcl src/bin/pgtclsh

do-build:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${ALL_TARGET}
.endfor

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}
.endfor

post-install:
	${GTAR} zxCf ${PREFIX}/man ${WRKSRC}/doc/man.tar.gz		\
		`${SED} -e "s|#.*||" ${FILESDIR}/man.tcl`

.include "../../mk/bsd.pkg.mk"
