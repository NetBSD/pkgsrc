# $NetBSD: Makefile,v 1.15 2004/03/26 02:27:40 wiz Exp $
#

DISTNAME=	gtetrinet-0.7.1
PKGREVISION=	9
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtetrinet/0.7/}

MAINTAINER=	benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=	http://gtetrinet.sourceforge.net/
COMMENT=	Multiplayer tetris game for GNOME2

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome2-dirs>=1.5:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.prefs.mk"

# IPv6 support
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

GCONF2_SCHEMAS=		gtetrinet.schemas

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
