# $NetBSD: Makefile,v 1.5 2009/02/10 17:33:52 joerg Exp $

DISTNAME=	fping-2.4b2_to-ipv6
PKGNAME=	fping6-2.4b2
CATEGORIES=	net
MASTER_SITES=	http://www.fping.com/download/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.fping.com/
COMMENT=	Quickly ping many hosts w/o flooding the network

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

SPECIAL_PERMS+=		sbin/fping6 ${SETUID_ROOT_PERMS}

post-patch:
	@${MV} ${WRKSRC}/fping.8 ${WRKSRC}/fping6.8

PKG_OPTIONS_VAR=		PKG_OPTIONS.fping6
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
