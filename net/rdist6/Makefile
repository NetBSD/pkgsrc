# $NetBSD: Makefile,v 1.4 1999/08/29 12:26:19 kim Exp $
#

DISTNAME=	rdist-6.1.4
CATEGORIES=	net
MASTER_SITES=	http://www.MagniComp.com/download/rdist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.MagniComp.com/rdist/

RDIST6_NAME=	rdist6

INSTALL_TARGET=	install install.man
MAKE_ENV+=	RDIST6_NAME=${RDIST6_NAME}

pre-patch:
	@${CP} \
	    ${FILESDIR}/mf.netbsd \
	    ${FILESDIR}/os-netbsd.h \
	    ${WRKSRC}/config

post-install:
	@strip ${PREFIX}/bin/${RDIST6_NAME}
	@strip ${PREFIX}/bin/rdistd

.include "../../mk/bsd.pkg.mk"
