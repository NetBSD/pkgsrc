# $NetBSD: Makefile,v 1.46 2024/06/22 12:39:59 gdt Exp $

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

# Force disable all spell checkers that are not handled in options.mk,
# to avoid them being unintentionally found if installed.
CONFIGURE_ARGS+=	--without-nuspell
CONFIGURE_ARGS+=	--without-hspell	# Hebrew
CONFIGURE_ARGS+=	--without-voikko	# Finnish

# \todo The package previously relied on finding applespell on mac,
# without forcing it on, and without explaining this.  Change to
# enable on mac (but not on darwin without mac!).
#CONFIGURE_ARGS+=	--without-applespell

# needed for testing
CONFIGURE_ARGS+=	--enable-relocatable
TEST_TARGET=		check

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.unittest-cpp=	build	# XXX: for tests
.include "../../devel/unittest-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
