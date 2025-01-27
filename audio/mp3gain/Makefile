# $NetBSD: Makefile,v 1.6 2025/01/27 20:21:14 rillig Exp $

DISTNAME=		${PKGNAME:S/./_/g}-src
PKGNAME=		mp3gain-1.6.2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp3gain/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mp3gain.sourceforge.net/
COMMENT=		Loudness normalizer for MP3 files
LICENSE=		gnu-lgpl-v2

WRKSRC=			${WRKDIR}
USE_TOOLS+=		gmake

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mp3gain ${DESTDIR}${PREFIX}/bin

.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
