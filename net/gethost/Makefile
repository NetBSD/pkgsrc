# $NetBSD: Makefile,v 1.1.1.1 2002/07/10 02:12:00 kim Exp $

CATEGORIES=	net
DISTNAME=	gethost-0.03

MASTER_SITES=	http://www.reedmedia.net/software/gethost/
MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.reedmedia.net/software/gethost/
COMMENT=	A hostname and IP resolver for testing /etc/hosts, nsswitch.conf

ALL_TARGET=	gethost

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gethost ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gethost.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
