# $NetBSD: Makefile,v 1.3 2000/09/01 14:20:17 jwise Exp $

PKGNAME=		tcl-${DISTNAME}

DEPENDS+=		postgresql-${PG_VERS}:../../databases/postgresql
DEPENDS+=		tcl-8.3.2:../../lang/tcl

TCLSH=			${LOCALBASE}/bin/tclsh
TCL_INCDIR=		${LOCALBASE}/include
TCL_CONFIGDIR=		${LOCALBASE}/lib
USE_LIBTOOL=

MAKE_ENV+=		INSTALLED_LIBPQ=1

CONFIGURE_ARGS+=	--without-perl --without-odbc
CONFIGURE_ARGS+=	--with-tcl \
			--with-tclconfig="${TCL_CONFIGDIR}" \
			--with-includes="${TCL_INCDIR}" \
			--with-libraries="${LOCALBASE}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"

DIRS_TO_BUILD=		interfaces/libpgtcl \
			bin/pgtclsh \
			pl/tcl

do-build:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${ALL_TARGET}
.endfor

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}
.endfor
	strip ${PREFIX}/bin/pgtclsh
	${GTAR} zxCf ${PREFIX}/man \
		${WRKDIR}/${DISTNAME}/doc/man.tar.gz \
		`${SED} -e "s/#.*//" ${FILESDIR}/man.tcl`

.include "../../databases/postgresql/Makefile.common"
