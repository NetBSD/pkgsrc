# $NetBSD: Makefile,v 1.9 2026/11/14 06:35:45 wiz Exp $

DISTNAME=	pmw-5.34
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=PhilipHazel/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://philiphazel.github.io/pmw/
COMMENT=	High quality music typesetting program
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake

BUILD_TARGET=	build
TEST_TARGET=	check

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

CONFIGURE_ARGS+=	--enable-musicxml
CONFIGURE_ARGS+=	--enable-pdf-default

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/spec.pdf ${DESTDIR}${PREFIX}/share/doc/pmw/spec.pdf

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
