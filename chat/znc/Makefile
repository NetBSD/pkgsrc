# $NetBSD: Makefile,v 1.45 2024/05/21 09:43:06 nikita Exp $

DISTNAME=	znc-1.9.0
CATEGORIES=	chat
MASTER_SITES=	https://znc.in/releases/archive/
DISTFILES=	${DEFAULT_DISTFILES} znc-palaver-1.2.2.tar.gz
SITES.znc-palaver-1.2.2.tar.gz= -${MASTER_SITE_GITHUB:=cocodelabs/znc-palaver/archive/}1.2.2.tar.gz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://znc.in/
COMMENT=	Advanced IRC bouncer with IPv6 and SSL support
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config msgfmt
USE_LANGUAGES=	c c++
MANCOMPRESSED=	yes

USE_CXX_FEATURES+=	c++11

LDFLAGS.SunOS+=	-lsocket -lnsl

PLIST_SRC=	PLIST

BUILD_DEFS+=	VARBASE
BUILD_DEFS+=	PKG_SYSCONFDIR
BUILD_DEFS+=	ZNC_USER
BUILD_DEFS+=	ZNC_GROUP

PKG_SYSCONFSUBDIR=	${PKGBASE}

.include "../../mk/bsd.prefs.mk"

ZNC_USER?=	znc
ZNC_GROUP?=	znc
PKG_GROUPS=	${ZNC_GROUP}
PKG_USERS=	${ZNC_USER}:${ZNC_GROUP}

PKG_GROUPS_VARS=	ZNC_USER
PKG_USERS_VARS=		ZNC_GROUP

RCD_SCRIPTS+=		znc
PTHREAD_AUTO_VARS=	yes

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR} ${ZNC_USER} ${ZNC_GROUP} 0755

PKGCONFIG_OVERRIDE+=	znc.pc.in

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing absolute paths in znc.1 manpage.
SUBST_FILES.man=	man/znc.1
SUBST_SED.man=		-e 's|/usr/local|${PREFIX}|g'

post-extract:
	${CP} ${WRKDIR}/znc-palaver-1.2.2/palaver.cpp ${WRKSRC}/modules/

.include "options.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
