# $NetBSD: Makefile,v 1.2 2012/10/02 23:47:59 asau Exp $

PKGNAME=		mp3gain-1.5.2
DISTNAME=		${PKGNAME:S/./_/g}-src
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp3gain/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mp3gain.sourceforge.net/
COMMENT=		Loudness normalizer for MP3 files

WRKSRC=			${WRKDIR}
USE_TOOLS+=		gmake
LICENSE=		gnu-lgpl-v2

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mp3gain ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
