# $NetBSD: Makefile,v 1.6 2004/12/03 15:15:03 wiz Exp $
#

DISTNAME=	ascii-3.0
CATEGORIES=	misc
MASTER_SITES=	http://www.tuxedo.org/~esr/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tuxedo.org/~esr/software.html
COMMENT=	ASCII character table program

BUILD_TARGET= ascii

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ascii ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ascii.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ascii
	${INSTALL_DATA} ${WRKSRC}/ascii.cgi ${PREFIX}/share/examples/ascii

.include "../../mk/bsd.pkg.mk"
