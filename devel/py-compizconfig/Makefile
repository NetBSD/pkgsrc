# $NetBSD: Makefile,v 1.6 2010/02/14 18:08:48 joerg Exp $
#

PKGVER=			0.8.4
DISTNAME=		compizconfig-python-${PKGVER}
PKGNAME=		${PYPKGPREFIX}-compizconfig-${PKGVER}
CATEGORIES=		devel gnome
MASTER_SITES=		http://releases.compiz.org/${PKGVER}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://compiz.org/
COMMENT=		Python bindings for libcompizconfig
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake

PYTHON_VERSIONS_ACCEPTED=	26 25

PY_PATCHPLIST=		yes

BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

.include "../../wm/compiz/buildlink3.mk"
.include "../../devel/libcompizconfig/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
