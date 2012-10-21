# $NetBSD: Makefile,v 1.8 2012/10/21 10:27:14 cheusov Exp $
#

.include "../../audio/libmpg123/Makefile.common"

PKGNAME=	libmpg123-${LIBMPG123_VERSION}
COMMENT=	MPEG layer 1, 2, and 3 decoder library
MAINTAINER=	pkgsrc-users@NetBSD.org
LICENSE=	gnu-lgpl-v2

PKGCONFIG_OVERRIDE+=	libmpg123.pc.in

AUTO_MKDIRS=		yes

BUILD_DIRS=		src/libmpg123
INSTALL_DIRS=		src/libmpg123

post-extract:
	${ECHO} "#!${CONFIG_SHELL}${.newline}${TRUE}" > \
		${WRKSRC}/libltdl/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/libmpg123.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
