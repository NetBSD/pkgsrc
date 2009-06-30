# $NetBSD: Makefile,v 1.8 2009/06/30 00:07:15 joerg Exp $

DISTNAME=	e-uae-0.8.28
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.rcdrummond.net/uae/e-uae-0.8.28/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.rcdrummond.net/uae/
COMMENT=	Enhanced Ubiquitous Amiga Emulator

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

CONFLICTS+=	uae-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.4

.include "options.mk"

INSTALLATION_DIRS=	share/doc/uae \
			share/applications

post-install:
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.txt ${DESTDIR}${PREFIX}/share/doc/uae
	${INSTALL_DATA} ${FILESDIR}/e-uae.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
