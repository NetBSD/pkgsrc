# $NetBSD: Makefile,v 1.7 2007/08/08 03:13:37 wulf Exp $

DISTNAME=	gr-howto-write-a-block-${VERSION}
CATEGORIES=	ham
PKGNAME=	gnuradio-howto-${VERSION}
COMMENT=	Documentation on creating GNU Radio signal processing blocks

.include	"../../meta-pkgs/gnuradio/Makefile.version"

USE_LIBTOOL=    yes
GNU_CONFIGURE=  yes
USE_LANGUAGES=  c c++
USE_TOOLS+=     gmake automake autoconf pkg-config

PY_PATCHPLIST=  yes
PYTHON_VERSIONS_ACCEPTED=       24 23

PYTHON_PATCH_SCRIPTS+=	src/python/qa_howto.py
PYTHON_PATCH_SCRIPTS+=	doc/qa_howto_1.py
PYTHON_PATCH_SCRIPTS+=	doc/make_numbered_listing.py

USE_LIBTOOL=    yes
GNU_CONFIGURE=  yes
USE_LANGUAGES=  c c++
USE_TOOLS+=     gmake automake autoconf pkg-config

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
