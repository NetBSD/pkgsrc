# $NetBSD: Makefile,v 1.5 2026/08/04 20:28:54 wiz Exp $

DISTNAME=	fsx-2009
CATEGORIES=	filesystems
MASTER_SITES=	#
DISTFILES=	fsx.c Makefile APPLE_LICENSE

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://codemonkey.org.uk/projects/fsx/
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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
