# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 14:49:38 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		postgresql-pltcl-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		PL/Tcl procedural language for the PostgreSQL backend

DEPENDS+=		postgresql-server>=${PG_BASE_VERS}:../../databases/postgresql-server
DEPENDS+=		tcl>=8.3.2:../../lang/tcl

TCLSH=			${LOCALBASE}/bin/tclsh
TCL_CONFIGDIR=		${LOCALBASE}/lib

CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${TCL_CONFIGDIR}"
CONFIGURE_ARGS+=	--with-includes="${LOCALBASE}/include"
CONFIGURE_ARGS+=	--with-libraries="${LOCALBASE}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"

DIRS_TO_BUILD=		src/pl/tcl

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

.include "../../mk/bsd.pkg.mk"
