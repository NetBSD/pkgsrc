# $NetBSD: Makefile,v 1.18 2007/04/13 21:02:44 adam Exp $

DISTNAME=	libspectrum-0.3.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/libspectrum.php
COMMENT=	ZX Spectrum emulator file format library

USE_TOOLS+=		gmake perl pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

DOCDIR=		${PREFIX}/share/doc/libspectrum

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/libspectrum.txt ${DOCDIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
