# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:49 tv Exp $

DISTNAME=		digikam-0.6.2
PKGREVISION=		1
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://digikam.sourceforge.net/
COMMENT=		KDE frontend to gphoto2

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

WRKSRC=		${WRKDIR}/digikam
BUILDLINK_DEPMETHOD.kdesdk=	build

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/kdesdk3/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
