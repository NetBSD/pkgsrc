# $NetBSD: Makefile,v 1.13 2005/12/05 20:50:58 rillig Exp $
#

DISTNAME=		m2crypto-0.12
PKGNAME=		${PYPKGPREFIX}-m2crypto-0.12
PKGREVISION=		2
CATEGORIES=		security python
MASTER_SITES=		http://sandbox.rulemaker.net/ngps/Dist/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sandbox.rulemaker.net/ngps/m2/
COMMENT=		Crypto and SSL toolkit for Python

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	23 22 21

BUILDLINK_DEPENDS.openssl+=	openssl>=0.9.7b

.include "../../lang/python/extension.mk"
.include "../../devel/swig-build/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
