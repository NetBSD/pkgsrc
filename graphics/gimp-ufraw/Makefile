# $NetBSD: Makefile,v 1.11 2005/10/04 12:58:13 gdt Exp $

DISTNAME=		ufraw-0.5
PKGNAME=		gimp-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ufraw/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://ufraw.sourceforge.net/
COMMENT=		GIMP plug-in for raw digicam import

GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake pkg-config
USE_TOOLS+=		perl:run pod2man

BUILDLINK_TRANSFORM+=	rm:-std=gnu99

CONFIGURE_ARGS+=	--enable-extras

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
