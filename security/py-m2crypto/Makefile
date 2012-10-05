# $NetBSD: Makefile,v 1.27 2012/10/05 10:14:46 apb Exp $
#

DISTNAME=		M2Crypto-0.21.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=		1
CATEGORIES=		security python
MASTER_SITES=		http://pypi.python.org/packages/source/M/M2Crypto/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://chandlerproject.org/bin/view/Projects/MeTooCrypto
COMMENT=		Crypto and SSL toolkit for Python
LICENSE=		m2crypto-license

PKG_DESTDIR_SUPPORT=	user-destdir

# constness is very different between openssl versions,
# it seems, and 0.9.7i is the version which currently is
# in pkgsrc and against which I fixed m2crypto to compile.
# -- wiz 20060115
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7i{,nb*}

.include "../../lang/python/extension.mk"
.include "../../lang/python/egg.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
