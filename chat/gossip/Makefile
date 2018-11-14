# $NetBSD: Makefile,v 1.110 2018/11/14 22:21:08 kleink Exp $
#

DISTNAME=	gossip-0.10.2
PKGREVISION=	54
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gossip/0.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gossip.imendio.org/
COMMENT=	GTK2 Jabber Instant Messaging client

BUILD_DEPENDS+=		p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

GCONF_SCHEMAS=		gossip.schemas

EGDIR=			${PREFIX}/share/examples/gossip
CONF_FILES=		${EGDIR}/sound/events/gossip.soundlist \
			${PKG_SYSCONFDIR}/sound/events/gossip.soundlist
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "../../chat/loudmouth/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
