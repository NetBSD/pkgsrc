# $NetBSD: Makefile,v 1.6 2026/09/02 00:53:37 maya Exp $

DISTNAME=		chezscheme-10.4.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=cisco/}
GITHUB_PROJECT=		ChezScheme
GITHUB_TAG=		v${PKGVERSION_NOREV}
GITHUB_SUBMODULES+=	lz4 lz4 ebb370ca83af193212df4dcbadcc5d87bc0de2f0 lz4
GITHUB_SUBMODULES+=	nanopass nanopass-framework-scheme bb47b5695a5bffdfd4d99ec9b349f0864b08e0d4 nanopass
GITHUB_SUBMODULES+=	dybvig stex afa607564a5662ffd748e824801277a6b5a3d11c stex
GITHUB_SUBMODULES+=	madler zlib da607da739fa6047df13e66a2af6b8bec7c2a498 zlib
GITHUB_SUBMODULES+=	racket zuo a288cbfe350403899311ca7d8267d570e781ed2c zuo

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
CONFIGURE_ARGS+=	--workarea=pkgsrc-build

CONFIGURE_ENV.NetBSD+=	PAXCTL=${PAXCTL:Q}

BUILD_TARGET=	build
TEST_TARGET=	test

# Chez uses its own idiosyncratic platform nomenclature, like ta6nb for:
#
# - t: threaded
# - a: amd64
# - 6: 64-bit
# - nb: NetBSD
#
# Rather than copy the logic mapping OPSYS/MACHINE_ARCH to it, read it
# out of the file where Chez stores it after configure.
#
# XXX There are three possible variables: m, defaultm, and mboot.
# mboot is probably wrong; not clear whether to use m or defaultm here.
PLIST_SUBST+=		CHEZ_PLATFORM=${CHEZ_PLATFORM}
PRINT_PLIST_AWK+=	\
	/^lib\/csv[0-9.]*\// \
		{ sub(/${CHEZ_PLATFORM}/, "$${CHEZ_PLATFORM}") }
CHEZ_PLATFORM=		${CHEZ_PLATFORM_sh:sh}
CHEZ_PLATFORM_sh=	\
	cd ${WRKSRC:Q} && \
	${AWK} -F= '$$1 == "m" { print $$2 }' <pkgsrc-build/Mf-config

.include "../../mk/pax.mk"
.include "../../mk/bsd.pkg.mk"
