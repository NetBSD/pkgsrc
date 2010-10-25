# $NetBSD: Makefile,v 1.7 2010/10/25 12:47:09 adam Exp $

DISTNAME=	clang-2.8
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
# XXX remove on next update
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	llvm-${PKGVERSION_NOREV}.tgz clang-${PKGVERSION_NOREV}.tgz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/llvm-${PKGVERSION_NOREV}

USE_LANGUAGES=		c c++
USE_TOOLS+=		chown perl:build gmake
GNU_CONFIGURE=		yes

MAKE_DIRS+=		etc/llvm

INSTALLATION_DIRS=	bin lib libexec

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

TEST_TARGET=	check unittests

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	Fixing llvm-configure PERL path
SUBST_STAGE.perl=	post-patch
SUBST_FILES.perl=	tools/llvm-config/llvm-config.in.in
SUBST_SED.perl=		-e 's,@PERL@,${PERL5},'

post-extract:
	mv ${WRKDIR}/clang-${PKGVERSION_NOREV} ${WRKDIR}/llvm-2.8/tools/clang

# XXX Darwin only?
pre-install:
	find ${WRKSRC}/tools/clang/include/clang -name '*.inc.tmp' -exec rm {} \;

.include "../../mk/bsd.pkg.mk"
