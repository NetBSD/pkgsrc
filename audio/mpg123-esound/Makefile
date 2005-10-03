# $NetBSD: Makefile,v 1.12 2005/10/03 15:17:14 joerg Exp $

PKGNAME=	mpg123-esound-${MPG123_VERSION}
PKGREVISION=	6
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with EsounD

TARGET_SUFFIX=	-esd

.include "../mpg123/Makefile.common"

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpg123 ${PREFIX}/bin/mpg123-esound
	${INSTALL_MAN} ${WRKSRC}/mpg123.1 ${PREFIX}/man/man1/mpg123-esound.1

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
