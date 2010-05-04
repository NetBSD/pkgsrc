# $NetBSD: Makefile,v 1.5 2010/05/04 16:52:16 drochner Exp $
#

DISTNAME=	clang-2.7
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
DISTFILES=	llvm-2.7.tgz clang-2.7.tgz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/llvm-2.7
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

TEST_TARGET=	check unittests

post-extract:
	${MV} ${WRKDIR}/clang-2.7 ${WRKDIR}/llvm-2.7/tools/clang

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
