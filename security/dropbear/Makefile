# $NetBSD: Makefile,v 1.2 2003/10/30 23:22:32 xtraeme Exp $

DISTNAME=	dropbear-0.38
CATEGORIES=	security
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matt.ucc.asn.au/dropbear/dropbear.html
COMMENT=	SSH2 server, aimed at embedded market

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAKEFLAGS+=	ROOT_USER=${ROOT_USER} ROOT_GROUP=${ROOT_GROUP}

.include "../../mk/bsd.pkg.mk"
