# $NetBSD: Makefile,v 1.1.1.1 2002/06/20 16:28:18 agc Exp $
# FreeBSD Id: ports/security/arirang/Makefile,v 1.2 2001/08/11 14:08:00 dwcjr Exp

DISTNAME=	arirang-1.6beta
PKGNAME=	arirang-1.6rc1
CATEGORIES=	security www
MASTER_SITES=	http://www.monkey.org/~pilot/arirang/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.monkey.org/~pilot/arirang/
COMMENT=	Powerful webserver security scanner

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/arirang/
	${INSTALL_DATA} ${WRKSRC}/*.uxe ${PREFIX}/share/arirang

.include "../../mk/bsd.pkg.mk"
