# $NetBSD: Makefile,v 1.55 2025/10/05 19:25:43 js Exp $

DISTNAME=		dino-0.5.0
PKGREVISION=		3
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_GITHUB:=dino/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/dino/dino/
COMMENT=	Modern XMPP (Jabber) chat client
LICENSE=	gnu-gpl-v3

DEPENDS+=	glib-networking-[0-9]*:../../net/glib-networking

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

# Leftover from 0.4.x.  Unclear which platforms/compilers.
# The first option does not appear after building.  For now, omit and see if there is breakage.
#BUILDLINK_TRANSFORM+=	opt:-Wno-incompatible-pointer-types-discards-qualifiers:-Wno-incompatible-pointer-types

# tests fail because of missing RPATH in plugins/omemo/omemo-test.
# This seems to be because of upstream's use of ORIGIN.
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/plugins/omemo
# For Darwin                                                                                                                                                                                                  
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/plugins/omemo

.include "../../devel/meson/build.mk"

# Upstream's dependency documentation is at
#   https://github.com/dino/dino/wiki/Build
# \todo Sort/group by upstream and add missing.

.include "../../chat/libomemo-c/buildlink3.mk"
.include "../../comms/srtp/buildlink3.mk"
.include "../../converters/qrencode/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.24
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../net/libnice/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
