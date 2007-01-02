# $NetBSD: Makefile,v 1.19 2007/01/02 20:17:15 xtraeme Exp $

DISTNAME=		digikamimageplugins-0.9.0
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://digikam.sourceforge.net/
COMMENT=		Plugins for Digikam's ImageEditor

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake msgfmt perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

.include "../../graphics/digikam/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
