# $NetBSD: Makefile,v 1.1.1.1 2000/11/25 18:37:13 jtb Exp $
#

DISTNAME=	ascii-3.0
CATEGORIES=	misc
MASTER_SITES=	http://www.tuxedo.org/~esr/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/software.html

ALL_TARGET= ascii

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ascii ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ascii.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ascii
	${INSTALL_DATA} ${WRKSRC}/ascii.cgi ${PREFIX}/share/examples/ascii

.include "../../mk/bsd.pkg.mk"
