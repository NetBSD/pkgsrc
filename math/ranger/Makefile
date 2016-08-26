# $NetBSD: Makefile,v 1.2 2016/08/26 17:17:22 joerg Exp $

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
PTHREAD_AUTO_VARS= yes

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ranger ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
