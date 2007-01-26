# $NetBSD: Makefile,v 1.22 2007/01/26 04:13:34 markd Exp $

DISTNAME=		digikamimageplugins-0.9.0
PKGREVISION=		2
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://digikam.sourceforge.net/
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
