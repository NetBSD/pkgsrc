# $NetBSD: Makefile,v 1.4 2005/05/22 20:08:04 jlam Exp $

DISTNAME=		digikamimageplugins-0.7.2
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://digikam.sourceforge.net/
COMMENT=		Plugins for Digikam's ImageEditor

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

.include "../../graphics/digikam/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
