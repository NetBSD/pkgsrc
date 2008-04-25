# $NetBSD: Makefile,v 1.9 2008/04/25 20:39:09 joerg Exp $

DISTNAME=	gr-howto-write-a-block-${VERSION}
CATEGORIES=	ham
PKGNAME=	gnuradio-howto-${VERSION}
COMMENT=	Documentation on creating GNU Radio signal processing blocks

.include	"../../meta-pkgs/gnuradio/Makefile.common"

PY_PATCHPLIST=  yes
PYTHON_PATCH_SCRIPTS+=	src/python/qa_howto.py
PYTHON_PATCH_SCRIPTS+=	doc/qa_howto_1.py
PYTHON_PATCH_SCRIPTS+=	doc/make_numbered_listing.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
