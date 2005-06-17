# $NetBSD: Makefile,v 1.10 2005/06/17 03:50:31 jlam Exp $
#

DISTNAME=	arirang-1.6
CATEGORIES=	security www
MASTER_SITES=	http://monkey.org/~pilot/arirang/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://monkey.org/~pilot/arirang/
COMMENT=	Powerful webserver security scanner

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/arirang/
	${INSTALL_DATA} ${WRKSRC}/scanrule/*.uxe ${PREFIX}/share/arirang

.include "../../mk/bsd.pkg.mk"
