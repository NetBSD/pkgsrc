# $NetBSD: Makefile,v 1.1.1.1 2002/04/01 05:46:36 explorer Exp $
#

DISTNAME=	cdpd-1.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	explorer@netbsd.org
HOMEPAGE=	
COMMENT=	Simple daemon to send Cisco Discovery Protocol packets

GNU_CONFIGURE=	YES

DEPENDS=	libnet-[0-9]*:../../devel/libnet

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdpd ${PREFIX}/sbin/cdpd
	${INSTALL_DATA} ${WRKSRC}/cdpd.8 ${PREFIX}/man/man8/cdpd.8

.include "../../mk/bsd.pkg.mk"
