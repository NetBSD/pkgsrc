# $NetBSD: Makefile,v 1.2 2005/01/23 20:41:49 recht Exp $
#

DISTNAME=		Mixminion-0.0.7.1
PKGNAME=		${DISTNAME:S/M/m/}
CATEGORIES=		security mail
MASTER_SITES=		http://mixminion.net/dist/0.0.7.1/

MAINTAINER=		pdh@wiredyne.com
HOMEPAGE=		http://mixminion.net/
COMMENT=		Mixminion impedes message traffic analysis

BUILDLINK_DEPENDS.openssl+=	openssl>=0.9.7d

CRYPTO=				YES
USE_BUILDLINK3= 		YES
PYTHON_VERSIONS_ACCEPTED=       24 23 22 21
PYDISTUTILSPKG=			YES

TEST_TARGET=			test

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
