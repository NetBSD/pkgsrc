# $NetBSD: Makefile,v 1.9 2005/02/05 16:11:47 adrianp Exp $
#

DISTNAME=	cdpd-1.0.2
#PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	explorer@NetBSD.org
COMMENT=	Simple daemon to send Cisco Discovery Protocol packets

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

BUILDLINK_DEPENDS.libnet+=	libnet-1.0.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdpd ${PREFIX}/sbin/cdpd
	${INSTALL_DATA} ${WRKSRC}/cdpd.8 ${PREFIX}/man/man8/cdpd.8

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
