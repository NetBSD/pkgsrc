# $NetBSD: Makefile,v 1.8 2005/01/18 17:30:59 drochner Exp $

DISTNAME=	dropbear-0.44
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dropbear
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dropbear

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
