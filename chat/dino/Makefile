# $NetBSD: Makefile,v 1.38 2024/05/29 16:31:29 adam Exp $

DISTNAME=		dino-0.4.3
PKGREVISION=		3
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_GITHUB:=dino/}
#GITHUB_RELEASE=	v${PKGVERSION_NOREV}
# use post-release branch commits to fix a build issue
GITHUB_TAG=		235efcdab9b792a8cc328f466cbe700c102cd48f

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/dino/dino/
COMMENT=	Modern XMPP (Jabber) chat client
LICENSE=	gnu-gpl-v3

DEPENDS+=	glib-networking-[0-9]*:../../net/glib-networking

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

CMAKE_ARGS+=		-DUSE_SOUP3:BOOL=ON

BUILDLINK_TRANSFORM+=	opt:-Wno-incompatible-pointer-types-discards-qualifiers:-Wno-incompatible-pointer-types

# make[2]: don't know how to make exports/xmpp-vala.vapi. Stop
MAKE_JOBS_SAFE=	no

.include "../../devel/cmake/build.mk"

.include "../../chat/libsignal-protocol-c/buildlink3.mk"
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
