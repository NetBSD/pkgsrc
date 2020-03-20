# $NetBSD: Makefile,v 1.13 2020/03/20 11:57:35 nia Exp $

DISTNAME=	fuse-utils-1.4.3
PKGNAME=	${DISTNAME:S/fuse/fuse-emulator/}
PKGREVISION=	1
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
