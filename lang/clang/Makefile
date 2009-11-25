# $NetBSD: Makefile,v 1.3 2009/11/25 12:32:30 hasso Exp $
#

DISTNAME=	clang-2.6
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
DISTFILES=	llvm-2.6.tar.gz clang-2.6.tar.gz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/llvm-2.6
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:build chown
USE_LANGUAGES+=	c c++
MAKE_DIRS+=	etc/llvm
USE_LIBTOOL=	yes

CONFIGURE_ARGS=	--enable-bindings=none	# no OCaml, please!

INSTALLATION_DIRS=	bin lib libexec

# This should be changed!
CONFIGURE_ARGS+= --enable-targets=host-only
#CONFIGURE_ARGS+= --disable-optimized

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm
CHECK_PORTABILITY_SKIP+= utils/buildit/.svn/text-base/build_llvm.svn-base

TEST_TARGET=	check unittests

post-extract:
	${MV} ${WRKDIR}/clang-2.6 ${WRKDIR}/llvm-2.6/tools/clang

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
