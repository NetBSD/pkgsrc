# $NetBSD: Makefile,v 1.1.1.1 2004/04/01 19:07:11 jmmv Exp $
#

DISTNAME=	nautilus-cd-burner-2.6.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/nautilus-cd-burner/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	CD burner view for Nautilus

DEPENDS+=		cdrecord-[0-9]*:../../sysutils/cdrecord
DEPENDS+=		gnome2-dirs>=1.5:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	gnome-vfs-2.0/modules

EGDIR=			${PREFIX}/share/examples/nautilus-cd-burner/gnome-vfs-2.0/modules
CONF_FILES=		${EGDIR}/mapping-modules.conf \
			${PKG_SYSCONFDIR}/mapping-modules.conf

GCONF2_SCHEMAS=		ncb.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
