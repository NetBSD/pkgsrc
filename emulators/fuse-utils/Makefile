# $NetBSD: Makefile,v 1.1.1.1 2003/09/16 10:01:34 adam Exp $

DISTNAME=	fuse-utils-0.6.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.srcf.ucam.org/~pak21/spectrum/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.srcf.ucam.org/~pak21/spectrum/fuse.html
COMMENT=	ZX Spectrum Emulator utilities

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

.include "../../devel/glib/buildlink2.mk"
.include "../../emulators/libspectrum/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
