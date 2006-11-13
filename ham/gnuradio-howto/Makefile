# $NetBSD: Makefile,v 1.6 2006/11/13 17:24:46 wulf Exp $

VERSION=	3.0.2
DISTNAME=	gr-howto-write-a-block-${VERSION}
CATEGORIES=	ham
PKGNAME=	gnuradio-howto-${VERSION}
MASTER_SITES?=	http://www.gnuradio.org/releases/gnuradio/
COMMENT=	Documentation on creating GNU Radio signal processing blocks

MAINTAINER?=    wulf@NetBSD.org
HOMEPAGE?=      http://www.gnu.org/software/gnuradio/

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
