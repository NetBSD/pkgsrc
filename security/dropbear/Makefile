# $NetBSD: Makefile,v 1.7 2004/10/03 00:18:08 tv Exp $

DISTNAME=	dropbear-0.43
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matt.ucc.asn.au/dropbear/dropbear.html
COMMENT=	SSH2 server, aimed at embedded market

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

MAKEFLAGS+=	ROOT_USER=${ROOT_USER} ROOT_GROUP=${ROOT_GROUP}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
