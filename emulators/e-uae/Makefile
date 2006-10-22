# $NetBSD: Makefile,v 1.5 2006/10/22 19:38:58 rillig Exp $

DISTNAME=	e-uae-0.8.28
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.rcdrummond.net/uae/e-uae-0.8.28/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.rcdrummond.net/uae/
COMMENT=	Enhanced Ubiquitous Amiga Emulator

CONFLICTS+=	uae-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uae
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.txt ${PREFIX}/share/doc/uae

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
