# $NetBSD: Makefile,v 1.1.1.1 2003/04/18 08:44:16 mjl Exp $
#

DISTNAME=	multitail-1.8
CATEGORIES=	misc sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.vanheusden.com/multitail/
COMMENT=	view one or multiple files

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multitail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/multitail.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
