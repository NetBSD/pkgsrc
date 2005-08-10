# $NetBSD: Makefile,v 1.7 2005/08/10 19:01:24 gdt Exp $
#

DISTNAME=		ufraw-0.4
PKGNAME=		gimp-ufraw-0.4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://ufraw.sourceforge.net/
COMMENT=		GIMP plug-in for raw digicam import

USE_TOOLS+=		gmake
BUILD_TARGET=		build
INSTALL_TARGET=		install-admin

BUILDLINK_TRANSFORM+=	rm:-std=gnu99

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
