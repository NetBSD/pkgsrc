# $NetBSD: Makefile,v 1.6 2003/06/02 01:17:20 jschauma Exp $
#

DISTNAME=	arirang-1.6
CATEGORIES=	security www
MASTER_SITES=	http://monkey.org/~pilot/arirang/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://monkey.org/~pilot/arirang/
COMMENT=	Powerful webserver security scanner

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/arirang/
	${INSTALL_DATA} ${WRKSRC}/scanrule/*.uxe ${PREFIX}/share/arirang

.include "../../mk/bsd.pkg.mk"
