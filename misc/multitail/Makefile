# $NetBSD: Makefile,v 1.2 2003/04/23 11:56:33 mjl Exp $
#

DISTNAME=	multitail-2.0
CATEGORIES=	misc sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.vanheusden.com/multitail/
COMMENT=	view one or multiple files

CFLAGS+=	-DUSE_CURSES=1 -DKEY_RESIZE=-1
LDFLAGS+=	-lutil

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multitail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/multitail.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
