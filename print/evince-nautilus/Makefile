# $NetBSD: Makefile,v 1.43 2012/03/03 00:13:50 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../print/evince/Makefile.common"

PKGNAME=		${DISTNAME:S/evince/evince-nautilus/}
PKGREVISION=		5
COMMENT=		File properties plugin for evince files

.include "options.mk"

INSTALL_DIRS=		properties

BUILDLINK_DEPMETHOD.libXt?=	build
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.14.0

.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
