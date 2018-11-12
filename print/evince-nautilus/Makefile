# $NetBSD: Makefile,v 1.103 2018/11/12 03:52:48 ryoon Exp $

.include "../../print/evince/Makefile.common"

PKGNAME=		${DISTNAME:S/evince/evince-nautilus/}
PKGREVISION=		64
COMMENT=		File properties plugin for evince files

.include "options.mk"

INSTALL_DIRS=		properties

BUILDLINK_DEPMETHOD.libXt?=	build
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.14.0

.include "../../print/evince/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
