# $NetBSD: Makefile,v 1.3 2004/03/26 02:27:49 wiz Exp $
#

DISTNAME=	SpreadModule-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/SpreadModule/spreadmodule/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.python.org/other/spread/
EXTRACT_SUFX=	.tgz

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.python.org/other/spread/
COMMENT=	Python bindings for the Spread messaging service

PYDISTUTILSPKG=	YES
USE_BUILDLINK3=	YES

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 21pth

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,/usr/local,${PREFIX},g'

.include "../../net/spread/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
