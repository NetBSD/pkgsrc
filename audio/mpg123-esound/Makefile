# $NetBSD: Makefile,v 1.3 2002/09/06 11:51:59 wiz Exp $

PKGNAME=	mpg123-esound-${MPG123_VERSION}
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with EsounD

TARGET_SUFFIX=	-esd

.include "../mpg123/Makefile.common"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpg123 ${PREFIX}/bin/mpg123-esound

.include "../../audio/esound/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
