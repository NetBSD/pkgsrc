# $NetBSD: Makefile,v 1.7 2004/11/29 23:01:14 explorer Exp $
#

DISTNAME=	cdpd-1.0.2
#PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	explorer@NetBSD.org
COMMENT=	Simple daemon to send Cisco Discovery Protocol packets

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdpd ${PREFIX}/sbin/cdpd
	${INSTALL_DATA} ${WRKSRC}/cdpd.8 ${PREFIX}/man/man8/cdpd.8

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
