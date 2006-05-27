# $NetBSD: Makefile,v 1.16.2.1 2006/05/27 11:24:06 ghen Exp $

PKGNAME=	mpg123-esound-${MPG123_VERSION}
PKGREVISION=	7
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with EsounD

MAINTAINER=	pkgsrc-users@NetBSD.org

TARGET_SUFFIX=	-esd

PKG_OPTIONS_VAR=PKG_OPTIONS.mpg123-esound
.include "../../audio/mpg123/Makefile.common"

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpg123 ${PREFIX}/bin/mpg123-esound
	${INSTALL_MAN} ${WRKSRC}/mpg123.1 ${PREFIX}/man/man1/mpg123-esound.1

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
