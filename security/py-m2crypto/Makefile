# $NetBSD: Makefile,v 1.6 2004/01/11 19:06:46 jschauma Exp $
#

DISTNAME=		m2crypto-0.12
PKGNAME=		${PYPKGPREFIX}-m2crypto-0.12
CATEGORIES=		security
MASTER_SITES=		http://sandbox.rulemaker.net/ngps/Dist/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sandbox.rulemaker.net/ngps/m2/
COMMENT=		Crypto and SSL toolkit for Python

USE_BUILDLINK2=			yes
PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	22pth 21pth

BUILDLINK_DEPENDS.openssl=	openssl>=0.9.7b

.include "../../lang/python/extension.mk"
.include "../../devel/swig-build/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
