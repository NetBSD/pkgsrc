# $NetBSD: Makefile,v 1.63 2026/08/08 06:37:42 adam Exp $

DISTNAME=	libspectrum-1.6.3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fuse-emulator.sourceforge.net/libspectrum.php
COMMENT=	ZX Spectrum emulator file format library
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake perl pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

DOCDIR=			${PREFIX}/share/doc/libspectrum
INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/libspectrum.txt ${DESTDIR}${DOCDIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
