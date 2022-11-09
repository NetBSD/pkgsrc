# $NetBSD: Makefile,v 1.12 2022/11/09 13:14:09 joerg Exp $

DISTNAME=	06d46e3de6f7
PKGNAME=	${PYPKGPREFIX}-open-vcdiff-0.1pre${DISTNAME}
PKGREVISION=	1
EGG_NAME=	openvcdiff-0.1
CATEGORIES=	devel python
MASTER_SITES=	https://bitbucket.org/bluehorn/openvcdiff-python/get/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/bluehorn/openvcdiff-python
COMMENT=	Python binding for open-vcdiff
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/bluehorn-openvcdiff-python-${DISTNAME}

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 06d46e3de6f7

.include "../../devel/open-vcdiff/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
