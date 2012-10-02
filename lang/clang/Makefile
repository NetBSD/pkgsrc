# $NetBSD: Makefile,v 1.14 2012/10/02 20:11:37 asau Exp $

DISTNAME=	clang-3.1
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
DISTFILES=	llvm-${PKGVERSION_NOREV}.src.tar.gz \
		clang-${PKGVERSION_NOREV}.src.tar.gz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/llvm-${PKGVERSION_NOREV}.src

USE_LANGUAGES=		c c++
USE_TOOLS+=		chown gmake perl pod2man pod2html
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-assertions
CONFIGURE_ARGS+=	--disable-bindings	# disable OCaml
CONFIGURE_ARGS+=	--disable-timestamps
CONFIGURE_ARGS+=	--enable-optimized
#CONFIGURE_ARGS+=	--enable-shared

MAKE_DIRS+=		etc/llvm

INSTALLATION_DIRS=	bin lib libexec

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

TEST_TARGET=	check unittests

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
PLIST_SUBST+=		SOEXT="dylib"
.else
PLIST_SUBST+=		SOEXT="so"
.endif

post-extract:
	mv ${WRKDIR}/clang-${PKGVERSION_NOREV}.src ${WRKSRC}/tools/clang

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
