# $NetBSD: Makefile,v 1.25 2007/04/01 14:20:16 wiz Exp $

DISTNAME=		digikamimageplugins-0.9.1
PKGREVISION=		1
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.digikam.org/
COMMENT=		Plugins for Digikam's ImageEditor

USE_TOOLS+=		gmake msgfmt perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/digikam/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
