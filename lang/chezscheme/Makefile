# $NetBSD: Makefile,v 1.1 2023/11/06 17:15:57 pho Exp $

# NOTE: The latest stable release, 9.6.4 at the moment, is a version
# released before merging Racket fork back to the main repository. We
# really need to use the git HEAD at the moment because it is far more
# portable than 9.6.4. Switch the package to stable when v10 is released.
CHEZ_VERSION=	9.9.9alpha2023.11.03

DISTNAME=		chezscheme-${CHEZ_VERSION}
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=cisco/}
GITHUB_PROJECT=		ChezScheme
GITHUB_TAG=		92c697d7d3c930367c268e2e4fb229fe3ee3f39c
GITHUB_SUBMODULES+=	lz4 lz4 d44371841a2f1728a3f36839fd4b7e872d0927d3 lz4
GITHUB_SUBMODULES+=	nanopass nanopass-framework-scheme 68990d02573faa555ee42919d5809de03f1268a0 nanopass
GITHUB_SUBMODULES+=	dybvig stex 5e4f0ca67bac448e19a24c09f12fc16d24cd6b6d stex
GITHUB_SUBMODULES+=	madler zlib 09155eaa2f9270dc4ed1fa13e2b4b2613e6e4851 zlib
GITHUB_SUBMODULES+=	racket zuo 493e9cd08147add01bba9247f36759f095b87678 zuo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cisco.github.io/ChezScheme/
COMMENT=	Cisco implementation of the Scheme programming language
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

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
