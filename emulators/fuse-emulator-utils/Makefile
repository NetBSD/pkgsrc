# $NetBSD: Makefile,v 1.7 2017/12/14 08:15:43 adam Exp $

DISTNAME=	fuse-utils-1.4.0
PKGNAME=	${DISTNAME:S/fuse/fuse-emulator/}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator utilities
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../emulators/libspectrum/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
