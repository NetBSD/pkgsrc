# $NetBSD: Makefile,v 1.4 2001/12/03 08:06:27 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		postgresql-pltcl-${PG_BASE_VERS}
COMMENT=		PL/Tcl procedural language for the PostgreSQL backend

USE_BUILDLINK_ONLY=			# defined
BUILDLINK_DEPENDS.postgresql-lib=	postgresql-lib>=${PG_BASE_VERS}

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

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../lang/tcl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
