# $NetBSD: Makefile,v 1.24 2019/07/18 15:16:46 prlw1 Exp $

DISTNAME=	pyatspi-2.33.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyatspi/at-spi2/}
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pyatspi/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Python Assistive Technology Service Provider Interface
# GPLv2 for pasytest, but tests are not built by default
LICENSE=	gnu-lgpl-v2

DEPENDS+=	at-spi2-core>=2.3.90:../../devel/at-spi2-core
DEPENDS+=	at-spi2-atk-[0-9]*:../../devel/at-spi2-atk
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PY_PATCHPLIST=	yes

CONFLICTS=	${PYPKGPREFIX}-at-spi-[0-9]*

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
