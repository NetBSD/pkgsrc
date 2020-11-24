# $NetBSD: Makefile,v 1.2 2020/11/24 18:27:00 nia Exp $

DISTNAME=	nvi2-2.2.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=lichray/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lichray/nvi2
COMMENT=	Multibyte fork of the nvi editor for BSD
LICENSE=	modified-bsd

CONFLICTS+=	nvi-[0-9]*
CONFLICTS+=	nvi-m17n-[0-9]*

USE_CMAKE=	yes

CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	build
BUILD_DIRS=	build

# gcc: error: unrecognized command line option '-fcolor-diagnostics'
BUILDLINK_TRANSFORM+=	rm:-fcolor-diagnostics

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "options.mk"

SUBST_CLASSES+=		curses
SUBST_STAGE.curses=	pre-configure
SUBST_MESSAGE.curses=	Correcting the path to curses.
SUBST_FILES.curses+=	CMakeLists.txt
SUBST_SED.curses+=	-e "s,HINTS /usr/lib,HINTS ${BUILDLINK_PREFIX.curses}/lib NO_DEFAULT_PATH,g"

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/nvi ${DESTDIR}${PREFIX}/bin/nex
	${INSTALL_PROGRAM} ${WRKSRC}/build/nvi ${DESTDIR}${PREFIX}/bin/nvi
	${INSTALL_MAN} ${WRKSRC}/man/vi.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nex.1
	${INSTALL_MAN} ${WRKSRC}/man/vi.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nvi.1

.include "../../mk/bsd.pkg.mk"
