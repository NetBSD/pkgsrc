# $NetBSD: Makefile,v 1.2 2024/05/02 13:22:34 pho Exp $

DISTNAME=		chezscheme-10.0.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=cisco/}
GITHUB_PROJECT=		ChezScheme
GITHUB_TAG=		v${PKGVERSION_NOREV}
GITHUB_SUBMODULES+=	lz4 lz4 d44371841a2f1728a3f36839fd4b7e872d0927d3 lz4
GITHUB_SUBMODULES+=	nanopass nanopass-framework-scheme 68990d02573faa555ee42919d5809de03f1268a0 nanopass
GITHUB_SUBMODULES+=	dybvig stex 5e4f0ca67bac448e19a24c09f12fc16d24cd6b6d stex
GITHUB_SUBMODULES+=	madler zlib 51b7f2abdade71cd9bb0e7a373ef2610ec6f9daf zlib
GITHUB_SUBMODULES+=	racket zuo ebdc0451c39c70ce88b3b6ab9ba2b8e389ec519a zuo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cisco.github.io/ChezScheme/
COMMENT=	Cisco implementation of the Scheme programming language
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes

.include "options.mk"

CONFIGURE_ARGS+=	--installprefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--installman=${PREFIX:Q}/${PKGMANDIR:Q}
CONFIGURE_ARGS+=	--installdoc=${PREFIX:Q}/doc/${PKGBASE}
CONFIGURE_ARGS+=	--temproot=${DESTDIR:Q}
CONFIGURE_ARGS+=	--installschemename=${PKGBASE}
CONFIGURE_ARGS+=	--installscriptname=${PKGBASE}-script
CONFIGURE_ARGS+=	--as-is # skip Git submodule update

BUILD_TARGET=	build
TEST_TARGET=	test

# Chez Scheme uses a very weird scheme of machine type identifier in file
# paths, and we don't want to replicate the logic in ${WRKSRC/configure
# here.
PLIST_TYPE=	dynamic

.include "../../mk/bsd.pkg.mk"
