# $NetBSD: Makefile,v 1.4 2004/04/25 11:48:31 dillo Exp $
#

DISTNAME=	dvidvi-1.0
CATEGORIES=	print
MASTER_SITES=	ftp://sunsite.univie.ac.at/pub/distfiles/

MAINTAINER=	dillo@NetBSD.org
COMMENT=	Select and/or rearrange pages in a TeX dvi file

NO_SRC_ON_FTP=	Unable to determine distribution license
NO_SRC_ON_CDROM=Unable to determine distribution license
NO_BIN_ON_FTP=	Unable to determine distribution license
NO_BIN_ON_CDROM=Unable to determine distribution license

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvidvi ${PREFIX}/bin/dvidvi
	${INSTALL_MAN} ${WRKSRC}/dvidvi.1 ${PREFIX}/man/man1/dvidvi.1

.include "../../mk/bsd.pkg.mk"
