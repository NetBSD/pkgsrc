# $NetBSD: Makefile,v 1.5 2001/02/16 14:17:43 wiz Exp $

.include "../../databases/postgresql/Makefile.common"

PKGNAME=		tk-${DISTNAME}

COMMENT=		Tk interface to PostgreSQL

DEPENDS+=		tcl-postgresql-${PG_VERS}:../../databases/tcl-postgresql
DEPENDS+=		tk>=8.3.2:../../x11/tk

EVAL_PREFIX+=		TCLDIR=tcl
TCLSH=			${TCLDIR}/bin/tclsh
TCL_INCDIR=		${TCLDIR}/include
TCL_CONFIGDIR=		${TCLDIR}/lib

EVAL_PREFIX+=		TKDIR=tk
TK_INCDIR=		${TKDIR}/include
TK_CONFIGDIR=		${TKDIR}/lib

USE_X11=		# defined

MAKE_ENV+=		INSTALLED_LIBPQ=1 INSTALLED_LIBPGTCL=1

CONFIGURE_ARGS+=	--without-perl --without-odbc
CONFIGURE_ARGS+=	--with-tcl \
			--with-tclconfig="${TCL_CONFIGDIR}" \
			--with-tkconfig="${TK_CONFIGDIR}" \
			--with-includes="${TCL_INCDIR} ${TK_INCDIR}" \
			--with-libraries="${LOCALBASE}/lib ${TCLDIR}/lib ${TKDIR}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"

do-build:
	cd ${WRKSRC}/bin/pgtclsh && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} pgtksh

do-install:
	cd ${WRKSRC}/bin/pgtclsh && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} install_tk
	strip ${PREFIX}/bin/pgtksh
	${GTAR} zxCf ${PREFIX}/man \
		${WRKDIR}/${DISTNAME}/doc/man.tar.gz \
		`${SED} -e "s/#.*//" ${FILESDIR}/man.tk`

.include "../../mk/bsd.pkg.mk"
