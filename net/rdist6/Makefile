# $NetBSD: Makefile,v 1.6 2000/01/18 10:50:04 agc Exp $
#

DISTNAME=	freerdist-0.91
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.astron.com/pub/freerdist/

MAINTAINER=	christos@netbsd.org
#HOMEPAGE=

RDIST6_NAME=	rdist6

INSTALL_TARGET=	install install.man
MAKE_ENV+=	RDIST6_NAME=${RDIST6_NAME}

CONFLICTS=	rdist6-*

post-install:
	@strip ${PREFIX}/bin/${RDIST6_NAME}
	@strip ${PREFIX}/bin/rdistd

.include "../../mk/bsd.pkg.mk"
