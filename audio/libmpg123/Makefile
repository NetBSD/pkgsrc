# $NetBSD: Makefile,v 1.5 2011/09/14 15:46:01 hans Exp $
#

.include "../../audio/libmpg123/Makefile.common"

PKGNAME=	libmpg123-${LIBMPG123_VERSION}
COMMENT=	MPEG layer 1, 2, and 3 decoder library

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	libmpg123.pc.in

AUTO_MKDIRS=		yes

BUILD_DIRS=		src/libmpg123
INSTALL_DIRS=		src/libmpg123

post-extract:
	${ECHO} "#!${CONFIG_SHELL}${.newline}${TRUE}" > \
		${WRKSRC:Q}/libltdl/configure

post-install:
	${INSTALL_DATA} ${WRKSRC:Q}/libmpg123.pc \
		${DESTDIR:Q}${PREFIX:Q}/lib/pkgconfig

.include "mpg123-options.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
MAKE_ENV+=	SunOS_LDFLAGS="-shared -mimpure-text"
.endif

.include "../../mk/bsd.pkg.mk"
