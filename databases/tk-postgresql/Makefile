# $NetBSD: Makefile,v 1.12 2002/04/04 07:41:07 jlam Exp $

PKGNAME=		tk-postgresql-${BASE_VERS}
COMMENT=		Tk interface to PostgreSQL

USE_BUILDLINK_ONLY=	YES

.include "../../databases/postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tk
CONFIGURE_ARGS+=	--with-tclconfig=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--with-tkconfig=${BUILDLINK_DIR}/lib
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${LOCALBASE}/bin/tclsh
MAKE_ENV+=		INSTALLED_LIBPQ=1 INSTALLED_LIBPGTCL=1

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

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../databases/tcl-postgresql/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
