# $NetBSD: Makefile,v 1.36 2012/03/03 00:13:16 wiz Exp $

DISTNAME=		kbarcode-2.0.7
PKGREVISION=		12
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kbarcode/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.kbarcode.net/
COMMENT=		KDE barcode and label printing application

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake gs:run perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
SET_LIBDIR=		yes

DEPENDS+=	barcode-[0-9]*:../../graphics/barcode

# Works only with KDE 3.3.x
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs>=3.3.0

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
