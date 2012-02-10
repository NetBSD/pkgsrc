# $NetBSD: Makefile,v 1.1.1.1 2012/02/10 17:28:16 drochner Exp $
#

DISTNAME=	at-spi2-atk-2.3.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/at-spi2-atk/2.3/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Assistive Technology Service Provider Interface A11y Toolkit
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=     gmake intltool msgfmt pkg-config
USE_LIBTOOL=	yes
USE_PKGLOCALEDIR=	yes

CONFLICTS=	at-spi-[0-9]*

BUILDLINK_API_DEPENDS.atk+=	atk>=2.1.5
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
