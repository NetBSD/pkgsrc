# $NetBSD: Makefile,v 1.52 2023/11/14 14:01:46 wiz Exp $

DISTNAME=	e-uae-0.8.29-WIP4
PKGNAME=	e-uae-0.8.28.99.4
PKGREVISION=	10
CATEGORIES=	emulators
MASTER_SITES=	http://www.rcdrummond.net/uae/${DISTNAME}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.rcdrummond.net/uae/
COMMENT=	Enhanced Ubiquitous Amiga Emulator

MAKE_JOBS_SAFE=		no

CONFLICTS+=	uae-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
LIBS.SunOS+=		-lsocket -lnsl

.include "options.mk"

INSTALLATION_DIRS=	share/doc/uae \
			share/applications

post-install:
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.txt ${DESTDIR}${PREFIX}/share/doc/uae
	${INSTALL_DATA} ${FILESDIR}/e-uae.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
