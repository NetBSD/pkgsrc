# $NetBSD: Makefile,v 1.3 2003/08/04 17:27:06 jmc Exp $
#

DISTNAME=		m2crypto-0.11
PKGNAME=		${PYPKGPREFIX}-m2crypto-0.11
CATEGORIES=		security
MASTER_SITES=		http://www.post1.com/home/ngps/m2/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.post1.com/home/ngps/m2/
COMMENT=		Crypto and SSL toolkit for Python

USE_BUILDLINK2=		yes
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	22pth 21pth
USE_OPENSSL_VERSION=	${OPENSSL_VERSION_097B}

.include "../../lang/python/extension.mk"
.include "../../devel/swig-build/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
