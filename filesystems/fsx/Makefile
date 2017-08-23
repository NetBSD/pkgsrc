# $NetBSD: Makefile,v 1.2 2017/08/23 17:54:05 jlam Exp $

DISTNAME=	fsx-2009
CATEGORIES=	filesystems
MASTER_SITES=	http://codemonkey.org.uk/projects/fsx/fsx-macosforge/
DISTFILES=	fsx.c Makefile APPLE_LICENSE

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codemonkey.org.uk/projects/fsx/
COMMENT=	File System Exerciser
LICENSE=	apple-public-source-license

DIST_SUBDIR=	${DISTNAME}
WRKSRC=		${WRKDIR}
USE_TOOLS+=	gmake
BUILD_TARGET=	fsx
MAKE_FLAGS=	CFLAGS=${CFLAGS:Q}

INSTALLATION_DIRS=	bin share/doc/fsx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fsx ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/APPLE_LICENSE ${DESTDIR}${PREFIX}/share/doc/fsx

.include "../../mk/bsd.pkg.mk"
