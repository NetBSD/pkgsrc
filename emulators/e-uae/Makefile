# $NetBSD: Makefile,v 1.6 2007/08/16 22:23:46 joerg Exp $

DISTNAME=	e-uae-0.8.28
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.rcdrummond.net/uae/e-uae-0.8.28/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.rcdrummond.net/uae/
COMMENT=	Enhanced Ubiquitous Amiga Emulator

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	uae-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "options.mk"

INSTALLATION_DIRS=	share/doc/uae

post-install:
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.txt ${DESTDIR}${PREFIX}/share/doc/uae

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
