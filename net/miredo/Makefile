# $NetBSD: Makefile,v 1.27 2021/05/15 07:01:31 nia Exp $

DISTNAME=		miredo-1.2.6
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.remlab.net/files/miredo/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.remlab.net/miredo/
COMMENT=		Teredo IPv6 tunneling
LICENSE=		gnu-gpl-v2

NOT_FOR_PLATFORM=	Interix-*-* NetBSD-[0-3].*-* SunOS-*-*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--enable-examplesdir=${EGDIR}
CONFIGURE_ARGS+=	--disable-sample-conf
CONFIGURE_ARGS+=	--enable-miredo-user=${MIREDO_USER}

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt msgmerge xgettext

PKG_SYSCONFSUBDIR?=	miredo
EGDIR=			${PREFIX}/share/examples/miredo
CONF_FILES=		${EGDIR}/miredo.conf ${PKG_SYSCONFDIR}/miredo.conf
CONF_FILES+=		${EGDIR}/miredo-server.conf \
			${PKG_SYSCONFDIR}/miredo-server.conf
CONF_FILES+=		${EGDIR}/client-hook ${PKG_SYSCONFDIR}/client-hook

RCD_SCRIPTS=		miredo
FILES_SUBST+=		MIREDO_USER=${MIREDO_USER:Q}

PKG_USERS_VARS+=	MIREDO_USER
PKG_GROUPS_VARS+=	MIREDO_GROUP
PKG_GROUPS+=		${MIREDO_GROUP}
PKG_USERS+=		${MIREDO_USER}:${MIREDO_GROUP}

BUILD_DEFS+=		VARBASE PKG_SYSCONFBASE

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libjudy/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
