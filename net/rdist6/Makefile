# $NetBSD: Makefile,v 1.1 1998/04/24 16:12:12 agc Exp $
#

DISTNAME=	rdist-6.1.4
CATEGORIES=	net
MASTER_SITES=	http://www.MagniComp.com/download/rdist/

MAINTAINER=	packages@netbsd.org

RDIST6_NAME=	rdist6

INSTALL_TARGET=	install install.man
MAKE_ENV+=	RDIST6_NAME=${RDIST6_NAME}
MAN1=		${RDIST6_NAME}.1
MAN8=		rdistd.8

post-install:
	@strip ${PREFIX}/bin/${RDIST6_NAME}
	@strip ${PREFIX}/bin/rdistd

.include "../../mk/bsd.pkg.mk"
