# $NetBSD: Makefile,v 1.4 2014/05/09 07:37:00 wiz Exp $

DISTNAME=	libhid-0.2.16
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/salix-sbo/files/13.37/libhid/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libhid.alioth.debian.org/
COMMENT=	Abstraction layer for HID-class devices over USB/serial

BUILD_DEPENDS+=	docbook-[0-9]*:../../textproc/docbook
#BUILD_DEPENDS+=	swig-[0-9]*:../../devel/swig

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.2.16

.include "../../lang/python/pyversion.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../lang/python/application.mk"
# PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
#.include "../../lang/python/extension.mk"
#.include "../../lang/python/distutils.mk"

.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
