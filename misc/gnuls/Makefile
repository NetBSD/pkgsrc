# $NetBSD: Makefile,v 1.22 2011/10/03 16:17:08 jmmv Exp $
#

.include "../../sysutils/coreutils/Makefile.common"

PKGNAME=	${DISTNAME:S/coreutils/gnuls/}
CATEGORIES=	misc

COMMENT=	GNU ls utility with color support

CONFLICTS=	coreutils-[0-9]* linuxls-[0-9]*

do-build:
	${RUN} cd ${WRKSRC}/lib && ${BUILD_MAKE_CMD} all
	${RUN} cd ${WRKSRC}/src && ${BUILD_MAKE_CMD} version.h dircolors ls

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dircolors \
		${DESTDIR}${PREFIX}/bin/${GNU_PROGRAM_PREFIX}dircolors
	${INSTALL_PROGRAM} ${WRKSRC}/src/ls \
		${DESTDIR}${PREFIX}/bin/${GNU_PROGRAM_PREFIX}ls
	${INSTALL_DATA} ${WRKSRC}/man/dircolors.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${GNU_PROGRAM_PREFIX}dircolors.1
	${INSTALL_DATA} ${WRKSRC}/man/ls.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${GNU_PROGRAM_PREFIX}ls.1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
