# $NetBSD: Makefile,v 1.2 2002/07/10 11:31:35 wiz Exp $

DISTNAME=	gethost-0.03
CATEGORIES=	net
MASTER_SITES=	http://www.reedmedia.net/software/gethost/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.reedmedia.net/software/gethost/
COMMENT=	hostname and IP resolver for testing /etc/hosts and nsswitch.conf

ALL_TARGET=	gethost

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gethost ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gethost.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
