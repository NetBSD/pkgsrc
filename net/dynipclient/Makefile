# $NetBSD: Makefile,v 1.6 2003/07/17 22:51:08 grant Exp $
#

DISTNAME=	dynip_3.00
PKGNAME=	dynipclient-3.00
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dynip.com/software/unix/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dynip.com/
COMMENT=	Client for the dynip.com dynamic DNS service

do-build:
	cd ${WRKSRC} && ./Configure freebsd ${PREFIX}/bin /etc ${PREFIX}/man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dynipadmin ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/dynipclient ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/*.1 ${PREFIX}/man/man1/
	${INSTALL_SCRIPT} ${FILESDIR}/dynipclient.sh ${PREFIX}/etc/rc.d/dynipclient

.include "../../mk/bsd.pkg.mk"
