# $NetBSD: Makefile,v 1.9 2004/07/22 09:16:04 recht Exp $
#

DISTNAME=		m2crypto-0.12
PKGNAME=		${PYPKGPREFIX}-m2crypto-0.12
PKGREVISION=		1
CATEGORIES=		security python
MASTER_SITES=		http://sandbox.rulemaker.net/ngps/Dist/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sandbox.rulemaker.net/ngps/m2/
COMMENT=		Crypto and SSL toolkit for Python

USE_BUILDLINK3=			yes
PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth

BUILDLINK_DEPENDS.openssl=	openssl>=0.9.7b

.include "../../lang/python/extension.mk"
.include "../../devel/swig-build/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
