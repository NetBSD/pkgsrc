# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:10 jlam Exp $
#

DISTNAME=	ascii-3.0
CATEGORIES=	misc
MASTER_SITES=	http://www.tuxedo.org/~esr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tuxedo.org/~esr/software.html
COMMENT=	ASCII character table program

BUILD_TARGET= ascii

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ascii ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ascii.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ascii
	${INSTALL_DATA} ${WRKSRC}/ascii.cgi ${PREFIX}/share/examples/ascii

.include "../../mk/bsd.pkg.mk"
