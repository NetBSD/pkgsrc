# $NetBSD: Makefile,v 1.8 2004/06/27 13:13:23 grant Exp $
#

DISTNAME=	arirang-1.6
CATEGORIES=	security www
MASTER_SITES=	http://monkey.org/~pilot/arirang/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://monkey.org/~pilot/arirang/
COMMENT=	Powerful webserver security scanner

USE_BUILDLINK3=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/arirang/
	${INSTALL_DATA} ${WRKSRC}/scanrule/*.uxe ${PREFIX}/share/arirang

.include "../../mk/bsd.pkg.mk"
