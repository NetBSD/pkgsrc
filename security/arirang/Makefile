# $NetBSD: Makefile,v 1.3 2002/07/21 15:33:54 wiz Exp $
#

DISTNAME=	arirang-1.6
CATEGORIES=	security www
MASTER_SITES=	http://www.monkey.org/~pilot/arirang/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.monkey.org/~pilot/arirang/
COMMENT=	Powerful webserver security scanner

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/arirang/
	${INSTALL_DATA} ${WRKSRC}/scanrule/*.uxe ${PREFIX}/share/arirang

.include "../../mk/bsd.pkg.mk"
