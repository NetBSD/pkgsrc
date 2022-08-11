# $NetBSD: Makefile,v 1.4 2022/08/11 05:08:06 gutteridge Exp $

DISTNAME=	syncterm-1.1-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=syncterm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://syncterm.bbsdev.net/
COMMENT=	ANSI-BBS terminal designed to connect to remote BBSs
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DIRS=	src/syncterm

USE_TOOLS+=	gmake perl gzip

MAKE_FILE=	GNUmakefile

MAKE_FLAGS+=	RELEASE=1
MAKE_FLAGS+=	SRC_ROOT=${WRKSRC}/src
MAKE_FLAGS+=	MAN_PREFIX=${PREFIX}/${PKGMANDIR:S,man$,,g}
MAKE_FLAGS+=	SYSTEM_LIST_DIR=${PKG_SYSCONFDIR}
MAKE_FLAGS+=	WITHOUT_CRYPTLIB=1

# incompatible with NetBSD curses - tries to access within cchar_t
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
