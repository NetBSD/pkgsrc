# $NetBSD: Makefile,v 1.1.1.1 2003/09/16 09:55:13 adam Exp $

DISTNAME=	fuse-0.6.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.srcf.ucam.org/~pak21/spectrum/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.srcf.ucam.org/~pak21/spectrum/fuse.html
COMMENT=	ZX Spectrum Emulator

USE_BUILDLINK2=	yes
USE_PERL5=	build
USE_X11=	yes
GNU_CONFIGURE=	yes

.include "../../x11/gtk/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../emulators/libspectrum/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
