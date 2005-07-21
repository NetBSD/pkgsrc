# $NetBSD: Makefile,v 1.6 2005/07/21 16:29:51 wiz Exp $
#

DISTNAME=		ufraw-0.4
PKGNAME=		gimp-ufraw-0.4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

MAINTAINER=		gdt@ir.bbn.com
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
