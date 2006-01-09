# $NetBSD: Makefile,v 1.15 2006/01/09 17:43:59 tron Exp $

PKGNAME=	mpg123-esound-${MPG123_VERSION}
PKGREVISION=	6
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with EsounD

MAINTAINER=	tech-pkg@NetBSD.org

TARGET_SUFFIX=	-esd

PKG_OPTIONS_VAR=PKG_OPTIONS.mpg123-esound
.include "../../audio/mpg123/Makefile.common"

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpg123 ${PREFIX}/bin/mpg123-esound
	${INSTALL_MAN} ${WRKSRC}/mpg123.1 ${PREFIX}/man/man1/mpg123-esound.1

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
