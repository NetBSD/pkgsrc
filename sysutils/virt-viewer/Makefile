# $NetBSD: Makefile,v 1.5 2020/06/02 08:24:48 adam Exp $

DISTNAME=	virt-viewer-8.0
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	https://releases.pagure.org/virt-viewer/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://virt-manager.org/
COMMENT=	Graphical VNC/SPice viewer for the guest OS
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake intltool pkg-config

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
