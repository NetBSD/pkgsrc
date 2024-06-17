# $NetBSD: Makefile,v 1.44 2024/06/17 12:16:51 gdt Exp $

DISTNAME=		enchant-2.8.1
PKGNAME=		${DISTNAME:S/enchant/enchant2/}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=AbiWord/}
GITHUB_PROJECT=		enchant
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://abiword.github.io/enchant/
COMMENT=		Generic spell checking library
LICENSE=		gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
# Upstream doesn't document, but configure.ac requires C++11.
USE_CXX_FEATURES+=	c++11

USE_TOOLS+=		autoconf gmake groff pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__

# unsupported in pkgsrc - other dictionaries can be used instead
# avoid PLIST problems
CONFIGURE_ARGS+=	--without-hspell
CONFIGURE_ARGS+=	--without-voikko

# needed for testing
CONFIGURE_ARGS+=	--enable-relocatable
TEST_TARGET=		check

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.unittest-cpp=	build	# XXX: for tests
.include "../../devel/unittest-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
