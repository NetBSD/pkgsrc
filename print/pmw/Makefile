# $NetBSD: Makefile,v 1.7 2026/02/04 20:53:59 prlw1 Exp $

DISTNAME=	pmw-5.33
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

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

CONFIGURE_ARGS+=	--enable-musicxml
CONFIGURE_ARGS+=	--enable-pdf-default

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/spec.pdf ${DESTDIR}${PREFIX}/share/doc/pmw/spec.pdf

.include "../../mk/bsd.pkg.mk"
