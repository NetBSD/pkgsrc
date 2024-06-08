# $NetBSD: Makefile,v 1.42 2024/06/08 11:53:12 wiz Exp $

DISTNAME=		enchant-2.8.0
PKGNAME=		${DISTNAME:S/enchant/enchant2/}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=AbiWord/}
GITHUB_PROJECT=		enchant
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://abiword.github.io/enchant/
COMMENT=		Generic spell checking library
LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		autoconf gmake groff pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__

# Mostly needed due to hunspell headers making c++98 default unacceptable.
FORCE_CXX_STD=		c++11
USE_CXX_FEATURES+=	c++11

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
