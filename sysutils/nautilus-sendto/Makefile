# $NetBSD: Makefile,v 1.2 2009/01/13 09:44:14 wiz Exp $
#

DISTNAME=		nautilus-sendto-1.1.1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/nautilus-sendto/1.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/nautilus/
COMMENT=		Convenience application to send a file via email or instant messenger

USE_PKGLOCALEDIR=	yes
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
GCONF_SCHEMAS=		nst.schemas
GNU_CONFIGURE=		yes

#XXX: needs libempathy-gtk >= 2.25.2
#.include "../../chat/empathy/buildlink3.mk"
# XXX: not in pkgsrc proper yet
#.include "../../wip/gajim/buildlink3.mk"
.include "../../chat/pidgin/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
# XXX: add option for thunderbird support? buildlink3.mk doesn't exist yet.
#.include "../../mail/thunderbird/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
# not possible to enable it yet, see 
# http://bugzilla.gnome.org/show_bug.cgi?id=556774
#.include "../../sysutils/nautilus-cd-burner/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
