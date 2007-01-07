# $NetBSD: Makefile,v 1.13 2007/01/07 09:14:02 rillig Exp $
#

DISTNAME=	cdpd-1.0.2
#PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	explorer@NetBSD.org
COMMENT=	Simple daemon to send Cisco Discovery Protocol packets

GNU_CONFIGURE=	YES

BUILDLINK_API_DEPENDS.libnet+=	libnet-1.0.*

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdpd ${PREFIX}/sbin/cdpd
	${INSTALL_DATA} ${WRKSRC}/cdpd.8 ${PREFIX}/${PKGMANDIR}/man8/cdpd.8

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
