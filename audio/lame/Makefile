# $NetBSD: Makefile,v 1.10 1999/11/09 16:52:03 hubertf Exp $
#

.include 	"Makefile.common"

MAINTAINER=     hubertf@netbsd.org
HOMEPAGE=       http://hive.me.gu.edu.au/not_lame/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/man/lame.1 ${PREFIX}/man/man1/lame.1

.include "../../mk/bsd.pkg.mk"
