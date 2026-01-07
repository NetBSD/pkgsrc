# $NetBSD: Makefile,v 1.52 2026/01/07 08:46:02 wiz Exp $

DISTNAME=	quassel-0.14.0
PKGREVISION=	27
CATEGORIES=	chat
MASTER_SITES=	https://quassel-irc.org/pub/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://quassel-irc.org/
COMMENT=	Modern, cross-platform, distributed IRC client
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_TOOLS+=	bash perl
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++14

REPLACE_BASH+=	po/update.sh
REPLACE_BASH+=	scripts/tx-sync.sh

REPLACE_PERL+=	data/scripts/inxi
REPLACE_PERL+=	data/scripts/mpris

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"
RCD_SCRIPTS=	quasselcore

.if ${INIT_SYSTEM} == "rc.d"
DEPENDS+=	daemonize-[0-9]*:../../sysutils/daemonize
.endif

QUASSELCORE_USER?=	quasselcore
QUASSELCORE_GROUP?=	quasselcore
PKG_GROUPS=		${QUASSELCORE_GROUP}
PKG_USERS=		${QUASSELCORE_USER}:${QUASSELCORE_GROUP}
PKG_GROUPS_VARS=	QUASSELCORE_GROUP
PKG_USERS_VARS=		QUASSELCORE_USER
FILES_SUBST+=		QUASSELCORE_USER=${QUASSELCORE_USER}
FILES_SUBST+=		QUASSELCORE_GROUP=${QUASSELCORE_GROUP}

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libdbusmenu-qt5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../textproc/sonnet/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
