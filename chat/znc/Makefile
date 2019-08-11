# $NetBSD: Makefile,v 1.9 2019/08/11 13:18:06 wiz Exp $

DISTNAME=	znc-1.7.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://znc.in/releases/archive/

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://znc.in/
COMMENT=	Advanced IRC bouncer with IPv6 and SSL support
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bsdtar gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
PKGCONFIG_OVERRIDE+=	znc.pc.in

PLIST_SRC=		PLIST
PLIST_SUBST+=		ZNC_USER="${ZNC_USER}"
PLIST_SUBST+=		PKG_SYSCONFDIR="${PKG_SYSCONFDIR}"
PLIST_SUBST+=		PKG_PREFIX="${PREFIX}"

PKG_SYSCONFSUBDIR=	${PKGBASE}

.include "../../mk/bsd.prefs.mk"

ZNC_USER?=		znc
ZNC_GROUP?=		znc
PKG_GROUPS=		${ZNC_GROUP}
PKG_USERS=		${ZNC_USER}:${ZNC_GROUP}
PKG_GROUPS_VARS=	ZNC_USER
PKG_USERS_VARS=		ZNC_GROUP

SUBST_CLASSES+=			fix-man-znc
SUBST_STAGE.fix-man-znc=	pre-configure
SUBST_MESSAGE.fix-man-znc=	Fixing absolute paths in znc.1 manpage.
SUBST_FILES.fix-man-znc=	man/znc.1
SUBST_SED.fix-man-znc=		-e 's,\~\/\.znc,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-man-znc+=		-e 's,\/usr\/local,${PREFIX},g'

SUBST_CLASSES+=			fix-tar
SUBST_STAGE.fix-tar=		pre-build
SUBST_MESSAGE.fix-tar=		Replace tar executable name.
SUBST_FILES.fix-tar+=		modules/modperl/Makefile.inc
SUBST_FILES.fix-tar+=		modules/modpython/Makefile.inc
SUBST_SED.fix-tar=		-e 's,tar -xf ,bsdtar -xf ,g'

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		PKG_SYSCONFDIR
BUILD_DEFS+=		ZNC_USER
BUILD_DEFS+=		ZNC_GROUP

RCD_SCRIPTS+=		znc
PTHREAD_AUTO_VARS=	yes

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR} ${ZNC_USER} ${ZNC_GROUP} 0755

MANCOMPRESSED=		yes

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
