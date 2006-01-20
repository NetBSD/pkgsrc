# $NetBSD: Makefile,v 1.9 2006/01/20 22:25:45 joerg Exp $

DISTNAME=		kbarcode-1.8.1
PKGREVISION=	2
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kbarcode/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.kbarcode.net/
COMMENT=		KDE barcode and label printing application

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake gs:run
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

DEPENDS+=	barcode-[0-9]*:../../graphics/barcode

# Works only with KDE 3.3.x
BUILDLINK_DEPENDS.kdelibs+=	kdelibs>=3.3.0

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
