# $NetBSD: Makefile,v 1.21 2008/01/24 11:14:26 tnn Exp $
#

DISTNAME=		m2crypto-0.13
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}.1
PKGREVISION=		2
CATEGORIES=		security python
MASTER_SITES=		http://sandbox.rulemaker.net/ngps/Dist/
EXTRACT_SUFX=		.zip

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		0.13p1.patch

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sandbox.rulemaker.net/ngps/m2/
COMMENT=		Crypto and SSL toolkit for Python

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21

# constness is very different between openssl versions,
# it seems, and 0.9.7i is the version which currently is
# in pkgsrc and against which I fixed m2crypto to compile.
# -- wiz 20060115
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7i{,nb*}

.include "../../lang/python/extension.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
