# $NetBSD: Makefile,v 1.3 2002/02/27 01:36:09 tv Exp $
#

DISTNAME=	dynip_3.00
PKGNAME=	dynipclient-3.00
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dynip.com/software/unix/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dynip.com/
COMMENT=	Client for the dynip.com dynamic DNS service

WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKSRC} && ./Configure freebsd ${PREFIX}/bin /etc ${PREFIX}/man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dynipadmin ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/dynipclient ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/*.1 ${PREFIX}/man/man1/
	${INSTALL_SCRIPT} ${FILESDIR}/dynipclient.sh ${PREFIX}/etc/rc.d/dynipclient

.include "../../mk/bsd.pkg.mk"
