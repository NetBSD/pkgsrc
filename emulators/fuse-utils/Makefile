# $NetBSD: Makefile,v 1.7 2004/10/03 00:14:40 tv Exp $

DISTNAME=	fuse-utils-0.7.0
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator utilities

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

LIBS+=			-lgcrypt
LIBS+=			-lgpg-error

.include "../../emulators/libspectrum/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
