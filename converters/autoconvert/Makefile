# $NetBSD: Makefile,v 1.11 2008/02/28 11:58:47 rillig Exp $

DISTNAME=	autoconvert-0.3.13
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://people.debian.org/~ygh/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://banyan.dlut.edu.cn/~ygh/
COMMENT=	Intelligent Chinese encoding converter

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
AUTO_MKDIRS=			yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/autoconvert
	${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${WRKSRC}/shed.* \
		${PREFIX}/share/examples/autoconvert

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
