# $NetBSD: Makefile,v 1.6 2001/05/14 14:54:16 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		tk-postgresql-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		Tk interface to PostgreSQL

DEPENDS+=		postgresql-lib>=${PG_BASE_VERS}:../../databases/postgresql-lib
DEPENDS+=		tcl-postgresql>=${PG_BASE_VERS}:../../databases/tcl-postgresql
DEPENDS+=		tk>=8.3.2:../../x11/tk

TCLSH=			${LOCALBASE}/bin/tclsh
TCL_CONFIGDIR=		${LOCALBASE}/lib
TK_CONFIGDIR=		${LOCALBASE}/lib

USE_X11=		# defined

MAKE_ENV+=		INSTALLED_LIBPQ=1 INSTALLED_LIBPGTCL=1

CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tk
CONFIGURE_ARGS+=	--with-tclconfig="${TCL_CONFIGDIR}"
CONFIGURE_ARGS+=	--with-tkconfig="${TK_CONFIGDIR}"
CONFIGURE_ARGS+=	--with-includes="${LOCALBASE}/include"
CONFIGURE_ARGS+=	--with-libraries="${LOCALBASE}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"

DIRS_TO_BUILD=		src/bin/pgtclsh
ALL_TARGET=		pgtksh
INSTALL_TARGET=		install-tk

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
		`${SED} -e "s|#.*||" ${FILESDIR}/man.tk`

.include "../../mk/bsd.pkg.mk"
