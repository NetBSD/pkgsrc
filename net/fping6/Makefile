# $NetBSD: Makefile,v 1.4 2005/11/08 15:25:07 tv Exp $

DISTNAME=	fping-2.4b2_to-ipv6
PKGNAME=	fping6-2.4b2
CATEGORIES=	net
MASTER_SITES=	http://www.fping.com/download/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.fping.com/
COMMENT=	Quickly ping many hosts w/o flooding the network

GNU_CONFIGURE=	YES

post-patch:
	@${MV} ${WRKSRC}/fping.8 ${WRKSRC}/fping6.8

post-install:
	${CHMOD} 4555 ${PREFIX}/sbin/fping6

PKG_OPTIONS_VAR=		PKG_OPTIONS.fping6
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
