# $NetBSD: Makefile,v 1.5 2001/02/16 14:17:42 wiz Exp $

.include "../../databases/postgresql/Makefile.common"

PKGNAME=		tcl-${DISTNAME}

COMMENT=		Tcl interface to PostgreSQL

DEPENDS+=		postgresql-${PG_VERS}:../../databases/postgresql
DEPENDS+=		tcl>=8.3.2:../../lang/tcl

EVAL_PREFIX+=		TCLDIR=tcl
TCLSH=			${TCLDIR}/bin/tclsh
TCL_INCDIR=		${TCLDIR}/include
TCL_CONFIGDIR=		${TCLDIR}/lib

MAKE_ENV+=		INSTALLED_LIBPQ=1

CONFIGURE_ARGS+=	--without-perl --without-odbc
CONFIGURE_ARGS+=	--with-tcl \
			--with-tclconfig="${TCL_CONFIGDIR}" \
			--with-includes="${TCL_INCDIR}" \
			--with-libraries="${LOCALBASE}/lib ${TCLDIR}/lib"
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

.include "../../mk/bsd.pkg.mk"
