# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:49 tv Exp $

DISTNAME=		digikamplugins-0.6.2
PKGREVISION=	1
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://digikam.sourceforge.net/
COMMENT=		Plugins for Digikam

DEPENDS+=		dcraw-[0-9]*:../../graphics/dcraw

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

WRKSRC=		${WRKDIR}/digikamplugins

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/digikam/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
