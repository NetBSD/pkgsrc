# $NetBSD: Makefile,v 1.1.1.1 2000/03/18 17:45:12 jlam Exp $

PKGNAME=		tcl-${DISTNAME}

DEPENDS+=		postgresql-6.5.3:../../databases/postgresql
DEPENDS+=		tcl-8.0.5:../../lang/tcl80

TCLSH=			${LOCALBASE}/bin/tclsh8.0
TCL_INCDIR=		${LOCALBASE}/include/tcl8.0
TCL_CONFIGDIR=		${LOCALBASE}/lib/tcl8.0

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

.include "../../databases/postgresql/Makefile.common"
