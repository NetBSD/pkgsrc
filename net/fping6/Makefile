# $NetBSD: Makefile,v 1.1.1.1 2003/03/24 15:21:36 bouyer Exp $

DISTNAME=	fping-2.4b2_to-ipv6
PKGNAME=	fping6-2.4b2
CATEGORIES=	net
MASTER_SITES=	http://www.fping.com/download/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.fping.com/
COMMENT=	Quickly ping many hosts w/o flooding the network

GNU_CONFIGURE=	YES

post-patch:
	@${MV} ${WRKSRC}/fping.8 ${WRKSRC}/fping6.8

post-install:
	${CHMOD} 4555 ${LOCALBASE}/sbin/fping6

.include "../../mk/bsd.pkg.mk"
