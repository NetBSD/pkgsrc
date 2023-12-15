# $NetBSD: Makefile,v 1.23 2023/12/15 17:58:52 zafer Exp $

DISTNAME=	mp3check-0.8.7
CATEGORIES=	audio
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/mp3check/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://jo.ath.cx/soft/mp3check/
COMMENT=	Check MP3 files for consistency
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

BUILD_TARGET=	mp3check

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3check ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mp3check.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
