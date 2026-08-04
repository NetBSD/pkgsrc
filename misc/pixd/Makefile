# $NetBSD: Makefile,v 1.3 2026/08/04 20:29:09 wiz Exp $

DISTNAME=	pixd-1.0.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=FireyFly/}
GITHUB_PROJECT=	pixd
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FireyFly/pixd
COMMENT=	Colourful visualization tool for binary files
LICENSE=	mit

USE_TOOLS+=	gmake

BUILD_TARGET=	pixd

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pixd ${DESTDIR}${PREFIX}/bin/pixd
	${INSTALL_DATA} ${WRKSRC}/pixd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pixd.1

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
