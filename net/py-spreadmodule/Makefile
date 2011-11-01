# $NetBSD: Makefile,v 1.12 2011/11/01 10:54:05 obache Exp $
#

DISTNAME=	SpreadModule-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/SpreadModule/spreadmodule/}
PKGREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	http://www.python.org/other/spread/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/other/spread/
COMMENT=	Python bindings for the Spread messaging service
LICENSE=	python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,/usr/local,${BUILDLINK_PREFIX.spread},g'

.include "../../net/spread/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
