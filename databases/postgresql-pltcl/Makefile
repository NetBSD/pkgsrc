# $NetBSD: Makefile,v 1.2 2001/06/21 21:40:08 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		postgresql-pltcl-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		PL/Tcl procedural language for the PostgreSQL backend

USE_BUILDLINK_ONLY=	# defined
POSTGRESQL_LIB_REQD=	${PG_BASE_VERS}

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../lang/tcl/buildlink.mk"

DEPENDS+=		postgresql-server>=${PG_BASE_VERS}:../../databases/postgresql-server

CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_DIR}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${LOCALBASE}/bin/tclsh

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
