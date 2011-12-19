# $NetBSD: Makefile,v 1.20 2011/12/19 15:03:18 wiz Exp $

DISTNAME=	fuse-utils-1.0.0
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator utilities
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		ac_cv_path_AUDIOFILE_CONFIG="pkg-config audiofile"

LIBS+=			-lgcrypt
LIBS+=			-lgpg-error

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../emulators/libspectrum/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
