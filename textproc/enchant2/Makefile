# $NetBSD: Makefile,v 1.31 2023/11/04 16:21:42 wiz Exp $

DISTNAME=		enchant-2.6.2
PKGNAME=		${DISTNAME:S/enchant/enchant2/}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=AbiWord/}
GITHUB_PROJECT=		enchant
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://abiword.github.io/enchant/
COMMENT=		Generic spell checking library
LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		autoconf groff pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__
INSTALLATION_DIRS+=	share/examples
MAKE_DIRS+=		${PREFIX}/share/enchant
CONF_FILES=		${PREFIX}/share/examples/enchant.ordering ${PREFIX}/share/enchant/enchant.ordering

# Mostly needed due to hunspell headers making c++98 default unacceptable.
FORCE_CXX_STD=		c++11
USE_CXX_FEATURES+=	c++11

# unsupported in pkgsrc - other dictionaries can be used instead
# avoid PLIST problems
CONFIGURE_ARGS+=	--without-hspell
CONFIGURE_ARGS+=	--without-voikko

# As of 2.3.2
# FAILURE: 230 out of 425 tests failed (390 failures).
TEST_TARGET=		check

post-install:
	cd ${DESTDIR}${PREFIX}/share && ${MV} enchant/enchant.ordering examples/enchant.ordering

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.unittest-cpp=	build	# XXX: for tests
.include "../../devel/unittest-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
