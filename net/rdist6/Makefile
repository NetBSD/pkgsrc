# $NetBSD: Makefile,v 1.5 2000/01/15 18:09:27 christos Exp $
#

DISTNAME=	freerdist-0.91
CATEGORIES=	net
MASTER_SITES=	ftp.astron.com:/pub/freerdist/

MAINTAINER=	christos@netbsd.org
RDIST6_NAME=	rdist6

INSTALL_TARGET=	install install.man
MAKE_ENV+=	RDIST6_NAME=${RDIST6_NAME}

post-install:
	@strip ${PREFIX}/bin/${RDIST6_NAME}
	@strip ${PREFIX}/bin/rdistd

.include "../../mk/bsd.pkg.mk"
