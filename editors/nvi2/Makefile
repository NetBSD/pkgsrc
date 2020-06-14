# $NetBSD: Makefile,v 1.1 2020/06/14 11:44:02 nia Exp $

DISTNAME=	nvi2-2.1.3
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

CONFIGURE_DIRS=	build
BUILD_DIRS=	build

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "options.mk"

SUBST_CLASSES+=		curses
SUBST_STAGE.curses=	pre-configure
SUBST_MESSAGE.curses=	Correcting the path to curses.
SUBST_FILES.curses+=	build/CMakeLists.txt
SUBST_SED.curses+=	-e "s,HINTS /usr/lib,HINTS ${BUILDLINK_PREFIX.curses}/lib NO_DEFAULT_PATH,g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/nvi ${DESTDIR}${PREFIX}/bin/nex
	${INSTALL_PROGRAM} ${WRKSRC}/build/nvi ${DESTDIR}${PREFIX}/bin/nvi
	${INSTALL_MAN} ${WRKSRC}/docs/man/vi.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nex.1
	${INSTALL_MAN} ${WRKSRC}/docs/man/vi.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nvi.1

.include "../../mk/bsd.pkg.mk"
