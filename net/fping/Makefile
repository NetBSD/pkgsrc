# $NetBSD: Makefile,v 1.9 2003/09/04 12:47:37 abs Exp $
# FreeBSD Id: ports/net/fping/Makefile,v 1.10 2000/04/20 20:18:57 mharo Exp

DISTNAME=	fping-2.4b2_to
PKGNAME=	fping-2.4b2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.fping.com/download/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.fping.com/
COMMENT=	Quickly ping many hosts w/o flooding the network

GNU_CONFIGURE=	YES

post-install:
	${CHMOD} 4555 ${LOCALBASE}/sbin/fping

.include "../../mk/bsd.pkg.mk"
