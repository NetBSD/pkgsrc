# $NetBSD: Makefile,v 1.1 2013/08/15 17:14:06 joerg Exp $
#

DISTNAME=	06d46e3de6f7
PKGNAME=	${PYPKGPREFIX}-open-vcdiff-0.1pre${DISTNAME}
EGG_NAME=	openvcdiff-0.1
CATEGORIES=	devel python
MASTER_SITES=	https://bitbucket.org/bluehorn/openvcdiff-python/get/
EXTRACT_SUFX=	.zip

FETCH_USING=	curl

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://bitbucket.org/bluehorn/openvcdiff-python
COMMENT=	Python binding for open-vcdiff
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/bluehorn-openvcdiff-python-${DISTNAME}

USE_LANGUAGES=	c c++

.include "../../devel/open-vcdiff/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
