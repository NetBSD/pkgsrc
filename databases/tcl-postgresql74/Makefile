# $NetBSD: Makefile,v 1.4 2005/12/02 20:00:18 joerg Exp $

PKGNAME=		tcl-postgresql74-${BASE_VERS}
COMMENT=		Tcl interface to PostgreSQL

.include "../postgresql74/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
TCLSH=			${BUILDLINK_PREFIX.tcl}/bin/tclsh
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		${WRKSRC}/src/port
BUILD_DIRS+=		${WRKSRC}/src/interfaces/libpgtcl
BUILD_DIRS+=		${WRKSRC}/src/bin/pgtclsh

pre-configure:
	${TOUCH} ${WRKSRC}/src/template/dragonfly
	${CP} ${WRKSRC}/src/backend/port/dynloader/freebsd.c \
		${WRKSRC}/src/backend/port/dynloader/dragonfly.c
	${CP} ${WRKSRC}/src/backend/port/dynloader/freebsd.h \
		${WRKSRC}/src/backend/port/dynloader/dragonfly.h
	${CP} ${WRKSRC}/src/backend/port/dynloader/freebsd.h \
		${WRKSRC}/src/backend/port/dynloader/dragonfly.h
	${CP} ${WRKSRC}/src/include/port/freebsd.h \
		${WRKSRC}/src/include/port/dragonfly.h
	${CP} ${WRKSRC}/src/makefiles/Makefile.freebsd \
		${WRKSRC}/src/makefiles/Makefile.dragonfly

post-install:
	cd ${PREFIX}/man && ${TAR} -zxf ${WRKSRC}/doc/man.tar.gz		\
		`${SED} -e "s|#.*||" ${FILESDIR}/man.tcl`

.include "../postgresql74-lib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
