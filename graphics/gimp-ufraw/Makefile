# $NetBSD: Makefile,v 1.25 2006/05/16 08:27:08 drochner Exp $

DISTNAME=		ufraw-0.8.1
PKGNAME=		gimp-${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://ufraw.sourceforge.net/
COMMENT=		GIMP plug-in for raw digicam import

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libexif --with-exiv2

USE_TOOLS+=		gmake pkg-config
USE_TOOLS+=		perl:run pod2man
USE_DIRS+=		xdg-1.1
USE_LANGUAGES+=		c++

# This package uses too much C99 code to be patched.
GCC_REQD+=		3.0
BUILDLINK_TRANSFORM+=	rm:-std=gnu99

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
