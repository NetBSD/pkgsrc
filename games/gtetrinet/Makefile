# $NetBSD: Makefile,v 1.76 2014/01/01 11:52:16 wiz Exp $
#

DISTNAME=	gtetrinet-0.7.11
PKGREVISION=	34
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtetrinet/0.7/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtetrinet.sourceforge.net/
COMMENT=	Multiplayer tetris game for GNOME2

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES

MAKE_FLAGS+=		gamesdir=${PREFIX}/bin
MAKE_FLAGS+=		schemadir=${PREFIX}/share/gconf/schemas

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtetrinet
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

GCONF_SCHEMAS=		gtetrinet.schemas

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
