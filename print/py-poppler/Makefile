# $NetBSD: Makefile,v 1.31 2017/11/24 22:15:59 wiz Exp $

DISTNAME=	pypoppler-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	24
CATEGORIES=	print
MASTER_SITES=	https://launchpad.net/poppler-python/trunk/development/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/poppler-python
COMMENT=	Python bindings for the Poppler PDF rendering library
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2

.include "../../lang/python/extension.mk"
.include "../../devel/atk/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler-glib+=	poppler-glib>=0.12.1
.include "../../print/poppler-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygtk2+=		${PYPKGPREFIX}-gtk2>=2.8.4
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
