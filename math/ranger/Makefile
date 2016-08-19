# $NetBSD: Makefile,v 1.1 2016/08/19 20:24:36 cheusov Exp $

DISTNAME=	ranger-0.4.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=imbs-hl/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/imbs-hl/ranger
COMMENT=	Fast Implementation of Random Forests
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}/source
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ranger ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
