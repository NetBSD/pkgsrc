# $NetBSD: Makefile,v 1.10 2003/07/17 22:51:47 grant Exp $
#

DISTNAME=	freerdist-0.92
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.astron.com/pub/freerdist/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Network file distribution/synchronisation utility

RDIST6_NAME=	rdist6

INSTALL_TARGET=	install install.man
MAKE_ENV+=	RDIST6_NAME=${RDIST6_NAME}

CONFLICTS=	rdist6-[0-9]*

post-install:
	@strip ${PREFIX}/bin/${RDIST6_NAME}
	@strip ${PREFIX}/bin/rdistd

.include "../../mk/bsd.pkg.mk"
