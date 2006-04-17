# $NetBSD: Makefile,v 1.5 2006/04/17 13:46:45 wiz Exp $
#

.include "../../print/evince/Makefile.common"

PKGNAME=		${DISTNAME:S/evince/evince-nautilus/}
PKGREVISION=		3

COMMENT=		File properties plugin for evince files

BUILD_DIRS=		libbackend lib properties
INSTALL_DIRS=		properties

.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
