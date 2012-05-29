# $NetBSD: Makefile,v 1.24 2012/05/29 18:19:28 cheusov Exp $
#

.include "../../sysutils/coreutils/Makefile.common"

PKGNAME=	${DISTNAME:S/coreutils/gnuls/}
PKGREVISION=	1
CATEGORIES=	misc

COMMENT=	GNU ls utility with color support

CONFLICTS=	coreutils-[0-9]* linuxls-[0-9]*

do-build:
	${RUN} cd ${WRKSRC}/lib && ${BUILD_MAKE_CMD} all
	${RUN} cd ${WRKSRC}/src && ${BUILD_MAKE_CMD} version.h
	${RUN} cd ${WRKSRC}/src && ${BUILD_MAKE_CMD} dircolors ls

INSTALLATION_DIRS=	bin gnu/bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dircolors \
		${DESTDIR}${PREFIX}/bin/gdircolors
	${INSTALL_PROGRAM} ${WRKSRC}/src/ls \
		${DESTDIR}${PREFIX}/bin/gls
	${INSTALL_DATA} ${WRKSRC}/man/dircolors.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gdircolors.1
	${INSTALL_DATA} ${WRKSRC}/man/ls.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gls.1
	set -e; cd ${DESTDIR}${PREFIX}/gnu/bin; \
	ln -s ../../bin/gls ls; \
	ln -s ../../bin/gdircolors dircolors

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
