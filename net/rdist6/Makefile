# $NetBSD: Makefile,v 1.3 1998/08/20 15:17:18 tsarna Exp $
#

DISTNAME=	rdist-6.1.4
CATEGORIES=	net
MASTER_SITES=	http://www.MagniComp.com/download/rdist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.MagniComp.com/rdist/

RDIST6_NAME=	rdist6

INSTALL_TARGET=	install install.man
MAKE_ENV+=	RDIST6_NAME=${RDIST6_NAME}

post-install:
	@strip ${PREFIX}/bin/${RDIST6_NAME}
	@strip ${PREFIX}/bin/rdistd

.include "../../mk/bsd.pkg.mk"
