# $NetBSD: Makefile,v 1.1.1.1 2004/09/27 23:24:23 seb Exp $

DISTNAME=		kbarcode-1.8.1
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kbarcode/}

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://www.kbarcode.net/
COMMENT=		KDE barcode and label printing application

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

DEPENDS+=	barcode-[0-9]*:../../graphics/barcode

# Works only with KDE 3.3.x
BUILDLINK_DEPENDS.kdelibs=     kdelibs>=3.3.0

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
