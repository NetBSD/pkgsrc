# $NetBSD: Makefile,v 1.3 2018/11/16 13:02:46 bsiegert Exp $
#

DISTNAME=		enchant-2.2.3
PKGNAME=		enchant2-2.2.3
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=AbiWord/}
GITHUB_PROJECT=		enchant
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://abiword.github.io/enchant/
COMMENT=		Generic spell checking library
LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config autoconf
USE_LANGUAGES=		c c++11
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__
INSTALLATION_DIRS+=	share/examples
MAKE_DIRS+=		${PREFIX}/share/enchant
CONF_FILES=		${PREFIX}/share/examples/enchant.ordering ${PREFIX}/share/enchant/enchant.ordering

# XXX: needs unittest-cpp as a test dependency
#TEST_TARGET=		check

post-install:
	cd ${DESTDIR}${PREFIX}/share && ${MV} enchant/enchant.ordering examples/enchant.ordering


.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
#BUILDLINK_DEPMETHOD.unittest-cpp=	build	# XXX: for tests
#.include "../../wip/unittest-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
