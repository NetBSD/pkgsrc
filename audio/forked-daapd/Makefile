# $NetBSD: Makefile,v 1.38 2024/05/29 16:31:19 adam Exp $

DISTNAME=	forked-daapd-27.4
PKGREVISION=	31
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=ejurgensen/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ejurgensen.github.io/forked-daapd
COMMENT=	DAAP (iTunes), MPD (musicpd), and RSP (Roku) media server
LICENSE=	gnu-gpl-v2

RCD_SCRIPTS=	forked-daapd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	VARBASE

MAKE_FLAGS+=	localstatedir=${VARBASE}

DAAPD_GROUP?=	daapd
DAAPD_USER?=	daapd

PKG_GROUPS=	${DAAPD_GROUP}
PKG_USERS=	${DAAPD_USER}:${DAAPD_GROUP}

EGDIR=		${PREFIX}/share/examples/forked-daapd

CONF_FILES+=	${EGDIR}/forked-daapd.conf ${PKG_SYSCONFDIR}/forked-daapd.conf

OWN_DIRS_PERMS+=	${VARBASE}/cache/forked-daapd \
			${DAAPD_USER} ${DAAPD_GROUP} 0755

.include "options.mk"
.include "../../devel/confuse/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2
.include "../../devel/libantlr3c/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.if ${OPSYS} != "Linux" && ${OPSYS} != "SunOS"
.  include "../../devel/libinotify/buildlink3.mk"
.endif
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=		sqlite3>=3.5.0
.include "../../databases/sqlite3/buildlink3.mk"
# what other operating systems have libdns_sd?
.if ${OPSYS} != "NetBSD"
.  include "../../net/avahi/buildlink3.mk"
.endif
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../textproc/mxml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libwebsockets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
