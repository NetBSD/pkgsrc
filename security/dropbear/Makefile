# $NetBSD: Makefile,v 1.1.1.1 2003/08/19 15:46:44 agc Exp $

DISTNAME=	dropbear-0.36
CATEGORIES=	security
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matt.ucc.asn.au/dropbear/dropbear.html
COMMENT=	ssh2 server, aimed at embedded market

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAKEFLAGS+=	ROOT_USER=${ROOT_USER} ROOT_GROUP=${ROOT_GROUP}

.include "../../mk/bsd.pkg.mk"
