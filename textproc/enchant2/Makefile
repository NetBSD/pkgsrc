# $NetBSD: Makefile,v 1.65 2026/10/09 17:39:31 wiz Exp $

DISTNAME=	enchant-2.8.21
PKGNAME=	${DISTNAME:S/enchant/enchant2/}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rrthomas/}
GITHUB_PROJECT=	enchant
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rrthomas.github.io/enchant/
COMMENT=	Generic spell checking library
LICENSE=	gnu-lgpl-v2.1

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gmake pkg-config
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__

# Force disable all spell checkers that are not handled in options.mk,
# to avoid them being unintentionally found if installed.
CONFIGURE_ARGS+=	--without-hspell	# Hebrew
CONFIGURE_ARGS+=	--without-nuspell
CONFIGURE_ARGS+=	--without-voikko	# Finnish

# \todo The package previously relied on finding applespell on mac,
# without forcing it on, and without explaining this.  Change to
# enable on mac (but not on darwin without mac!).
#CONFIGURE_ARGS+=	--without-applespell

# needed for testing
CONFIGURE_ARGS+=	--enable-relocatable
TEST_TARGET=		check

.include "options.mk"

# groff is troubled in macOS bulk builds, so just use mandoc everywhere
USE_TOOLS+=		mandoc
SUBST_CLASSES+=		groff
SUBST_SED.groff+=	-e 's,groff -mandoc,mandoc,'
SUBST_FILES.groff+=	lib/Makefile.in
SUBST_FILES.groff+=	src/Makefile.in
SUBST_STAGE.groff=	pre-configure
SUBST_MESSAGE.groff=	Prefer mandoc to groff.

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.76
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.unittest-cpp=	build	# XXX: for tests
.include "../../devel/unittest-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
