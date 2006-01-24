# $NetBSD: Makefile,v 1.40 2006/01/24 07:31:58 wiz Exp $
#

DISTNAME=	gossip-0.9
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gossip/0.9/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gossip.imendio.org/
COMMENT=	GTK2 Jabber Instant Messaging client

BUILD_DEPENDS+=		p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser
BUILD_USES_MSGFMT=	yes

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=       yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

GCONF2_SCHEMAS=		gossip.schemas

EGDIR=			${PREFIX}/share/examples/gossip
CONF_FILES=		${EGDIR}/sound/events/gossip.soundlist \
			${PKG_SYSCONFDIR}/sound/events/gossip.soundlist
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

.include "../../chat/loudmouth/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
