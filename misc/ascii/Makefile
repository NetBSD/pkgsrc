# $NetBSD: Makefile,v 1.4 2003/06/02 01:18:18 jschauma Exp $
#

DISTNAME=	ascii-3.0
CATEGORIES=	misc
MASTER_SITES=	http://www.tuxedo.org/~esr/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/software.html
COMMENT=	ASCII character table program

ALL_TARGET= ascii

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ascii ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ascii.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ascii
	${INSTALL_DATA} ${WRKSRC}/ascii.cgi ${PREFIX}/share/examples/ascii

.include "../../mk/bsd.pkg.mk"
