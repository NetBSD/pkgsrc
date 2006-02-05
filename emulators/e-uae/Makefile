# $NetBSD: Makefile,v 1.2 2006/02/05 23:09:00 joerg Exp $

DISTNAME=	e-uae-0.8.28
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.rcdrummond.net/uae/e-uae-0.8.28/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.rcdrummond.net/uae/
COMMENT=	Enhanced Ubiquitous Amiga Emulator

CONFLICTS+=	uae-*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uae
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.txt ${PREFIX}/share/doc/uae

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
