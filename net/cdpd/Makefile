# $NetBSD: Makefile,v 1.4 2003/08/30 14:01:18 seb Exp $
#

DISTNAME=	cdpd-1.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	explorer@NetBSD.org
COMMENT=	Simple daemon to send Cisco Discovery Protocol packets

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdpd ${PREFIX}/sbin/cdpd
	${INSTALL_DATA} ${WRKSRC}/cdpd.8 ${PREFIX}/man/man8/cdpd.8

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
