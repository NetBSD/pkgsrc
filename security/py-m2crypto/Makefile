# $NetBSD: Makefile,v 1.5 2003/11/12 03:39:43 jschauma Exp $
#

DISTNAME=		m2crypto-0.11
PKGNAME=		${PYPKGPREFIX}-m2crypto-0.11
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.post1.com/home/ngps/m2/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.post1.com/home/ngps/m2/
COMMENT=		Crypto and SSL toolkit for Python

USE_BUILDLINK2=			yes
PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	22pth 21pth

BUILDLINK_DEPENDS.openssl=	openssl>=0.9.7b

.include "../../lang/python/extension.mk"
.include "../../devel/swig-build/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
