# $NetBSD: Makefile,v 1.6 2011/04/15 08:34:00 obache Exp $

DISTNAME=	fping-2.4b2_to-ipv6
PKGNAME=	fping6-2.4b2
CATEGORIES=	net
MASTER_SITES=	http://www.fping.com/download/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.fping.com/
COMMENT=	Quickly ping many hosts w/o flooding the network

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_FEATURES+=	inet6

SPECIAL_PERMS+=		sbin/fping6 ${SETUID_ROOT_PERMS}

post-patch:
	@${MV} ${WRKSRC}/fping.8 ${WRKSRC}/fping6.8

.include "../../mk/bsd.pkg.mk"
