# $NetBSD: Makefile,v 1.2 2005/04/01 13:02:28 drochner Exp $
#

DISTNAME=		ufraw-0.4
PKGNAME=		gimp-ufraw-0.4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

MAINTAINER=		gdt@ir.bbn.com
HOMEPAGE=		http://ufraw.sourceforge.net/
COMMENT=		GIMP plug-in for raw digicam import

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
BUILD_TARGET=		build
INSTALL_TARGET=		install-admin

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
