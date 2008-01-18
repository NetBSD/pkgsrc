# $NetBSD: Makefile,v 1.22 2008/01/18 05:06:40 tnn Exp $

DISTNAME=		kbarcode-2.0.5
PKGREVISION=		5
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kbarcode/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.kbarcode.net/
COMMENT=		KDE barcode and label printing application

USE_TOOLS+=		gmake gs:run perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

DEPENDS+=	barcode-[0-9]*:../../graphics/barcode

# Works only with KDE 3.3.x
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs>=3.3.0

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
