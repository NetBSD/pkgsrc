# $NetBSD: Makefile,v 1.10 2004/06/26 17:09:09 grant Exp $
#

DISTNAME=	libspectrum-0.2.1
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/libspectrum.php
COMMENT=	ZX Spectrum emulator file format library

USE_PERL5=		build
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PERL=${PERL5}

DOCDIR=		${PREFIX}/share/doc/libspectrum

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/libspectrum.txt ${DOCDIR}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
