# $NetBSD: Makefile,v 1.6 2001/05/14 14:53:52 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		tcl-postgresql-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		Tcl interface to PostgreSQL

DEPENDS+=		postgresql-lib>=${PG_BASE_VERS}:../../databases/postgresql-lib
DEPENDS+=		tcl>=8.3.2:../../lang/tcl

TCLSH=			${LOCALBASE}/bin/tclsh
TCL_CONFIGDIR=		${LOCALBASE}/lib

MAKE_ENV+=		INSTALLED_LIBPQ=1

CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${TCL_CONFIGDIR}"
CONFIGURE_ARGS+=	--with-includes="${LOCALBASE}/include"
CONFIGURE_ARGS+=	--with-libraries="${LOCALBASE}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"

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
