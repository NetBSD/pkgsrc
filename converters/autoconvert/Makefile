# $NetBSD: Makefile,v 1.2 2002/10/09 14:09:33 wiz Exp $

DISTNAME=	autoconvert-0.3.13
CATEGORIES=	converters
MASTER_SITES=	http://people.debian.org/~ygh/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://banyan.dlut.edu.cn/~ygh/
COMMENT=	Intelligent Chinese encoding converter

USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/autoconvert
	${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${WRKSRC}/shed.* \
		${PREFIX}/share/examples/autoconvert

.include "../../devel/libgetopt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
