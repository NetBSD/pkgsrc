# $NetBSD: Makefile,v 1.4.4.1 2004/02/10 15:57:30 agc Exp $

PKGNAME=	mpg123-esound-${MPG123_VERSION}
PKGREVISION=	1
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with EsounD

TARGET_SUFFIX=	-esd

.include "../mpg123/Makefile.common"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpg123 ${PREFIX}/bin/mpg123-esound
	${INSTALL_MAN} ${WRKSRC}/mpg123.1 ${PREFIX}/man/man1/mpg123-esound.1

.include "../../audio/esound/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
