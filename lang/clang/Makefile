# $NetBSD: Makefile,v 1.10 2011/05/07 16:54:56 adam Exp $

DISTNAME=	clang-2.9
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
DISTFILES=	llvm-${PKGVERSION_NOREV}.tgz clang-${PKGVERSION_NOREV}.tgz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/llvm-${PKGVERSION_NOREV}

USE_LANGUAGES=		c c++
USE_TOOLS+=		chown perl:build gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-assertions
CONFIGURE_ARGS+=	--disable-bindings	# disable OCaml
CONFIGURE_ARGS+=	--disable-timestamps
CONFIGURE_ARGS+=	--enable-optimized

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

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	Fixing llvm-configure PERL path
SUBST_STAGE.perl=	post-patch
SUBST_FILES.perl=	tools/llvm-config/llvm-config.in.in
SUBST_SED.perl=		-e 's,@PERL@,${PERL5},'

post-extract:
	mv ${WRKDIR}/clang-${PKGVERSION_NOREV} ${WRKSRC}/tools/clang

.include "../../mk/bsd.pkg.mk"
