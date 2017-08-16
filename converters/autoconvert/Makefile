# $NetBSD: Makefile,v 1.15 2017/08/16 20:45:33 wiz Exp $

DISTNAME=	autoconvert-0.3.13
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://people.debian.org/~ygh/

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=	http://banyan.dlut.edu.cn/~ygh/
COMMENT=	Intelligent Chinese encoding converter

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
AUTO_MKDIRS=			yes

INSTALLATION_DIRS=	share/examples/autoconvert

post-install:
	${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${WRKSRC}/shed.* \
	    ${DESTDIR}${PREFIX}/share/examples/autoconvert

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
