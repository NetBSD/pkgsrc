# $NetBSD: Makefile,v 1.31 2024/05/16 06:15:36 wiz Exp $

DISTNAME=	virt-viewer-8.0
PKGREVISION=	29
CATEGORIES=	sysutils
MASTER_SITES=	https://releases.pagure.org/virt-viewer/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://virt-manager.org/
COMMENT=	Graphical VNC/SPice viewer for the guest OS
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake intltool pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/gtk-vnc/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../sysutils/spice-gtk/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
