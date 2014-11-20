# $NetBSD: Makefile,v 1.68 2014/11/20 16:04:16 wiz Exp $
#

.include "../../print/evince/Makefile.common"

PKGNAME=		${DISTNAME:S/evince/evince-nautilus/}
PKGREVISION=		29
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
