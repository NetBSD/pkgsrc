# $NetBSD: Makefile,v 1.2 2014/01/01 11:52:13 wiz Exp $

DISTNAME=	libhid-0.2.16

PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/salix-sbo/files/13.37/libhid/
LICENSE=	gnu-gpl-v2

MAINTAINER=    	pkgsrc-users@NetBSD.org
HOMEPAGE=       http://libhid.alioth.debian.org/
COMMENT=	Abstract'n layer for HID-class devices over USB/serial
#'		# to close above apostrophe
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

BUILD_DEPENDS+=	docbook-[0-9]*:../../textproc/docbook
#BUILD_DEPENDS+=	swig-[0-9]*:../../devel/swig

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

GNU_CONFIGURE=          yes

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
