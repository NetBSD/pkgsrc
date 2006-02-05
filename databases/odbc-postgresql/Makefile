# $NetBSD: Makefile,v 1.11 2006/02/05 23:08:32 joerg Exp $

.include "Makefile.common"

PKGNAME=		odbc-postgresql-${BASE_VERS}
PKGREVISION=		1
COMMENT=		ODBC interface to PostgreSQL

CONFIGURE_ARGS+=	--with-odbcinst=${PKG_SYSCONFDIR:Q}

post-extract:
	if [ -d ${WRKSRC}/src/backend/port/dynloader ]; then            \
		${CP} ${WRKSRC}/src/backend/port/dynloader/freebsd.c \
			${WRKSRC}/src/backend/port/dynloader/dragonfly.c; \
		${CP} ${WRKSRC}/src/backend/port/dynloader/freebsd.h \
			${WRKSRC}/src/backend/port/dynloader/dragonfly.h; \
		${CP} ${WRKSRC}/src/backend/port/dynloader/freebsd.h \
			${WRKSRC}/src/backend/port/dynloader/dragonfly.h; \
	fi
	if [ -d ${WRKSRC}/src/template ]; then                          \
		${TOUCH} ${WRKSRC}/src/template/dragonfly;              \
	fi
	if [ -d ${WRKSRC}/src/include/port ]; then                      \
		${CP} ${WRKSRC}/src/include/port/freebsd.h              \
			${WRKSRC}/src/include/port/dragonfly.h;         \
	fi
	if [ -d ${WRKSRC}/src/makefiles ]; then                         \
		${CP} ${WRKSRC}/src/makefiles/Makefile.freebsd          \
			${WRKSRC}/src/makefiles/Makefile.dragonfly;     \
	fi


.include "../../mk/bsd.pkg.mk"
