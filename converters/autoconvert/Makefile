# $NetBSD: Makefile,v 1.1.1.1 2002/06/19 09:25:25 agc Exp $

DISTNAME=	autoconvert-0.3.13
CATEGORIES=	converters
MASTER_SITES=	http://people.debian.org/~ygh/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://banyan.dlut.edu.cn/~ygh/
COMMENT=	Intelligent Chinese encoding converter

USE_LIBTOOL=	yes
USE_GMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/autoconvert
	${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${WRKSRC}/shed.* \
		${PREFIX}/share/examples/autoconvert

.include "../../devel/libgetopt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
