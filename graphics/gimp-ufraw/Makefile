# $NetBSD: Makefile,v 1.16 2005/11/25 21:23:15 wiz Exp $

DISTNAME=		ufraw-0.6
PKGNAME=		gimp-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://ufraw.sourceforge.net/
COMMENT=		GIMP plug-in for raw digicam import

GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake pkg-config
USE_TOOLS+=		perl:run pod2man

# This package uses too much C99 code to be patched.
GCC_REQD+=		3.0
BUILDLINK_TRANSFORM+=	rm:-std=gnu99

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
