# $NetBSD: Makefile,v 1.23 2013/11/20 20:04:38 adam Exp $

DISTNAME=	gr-howto-write-a-block-${VERSION}
PKGREVISION=	10
CATEGORIES=	ham
PKGNAME=	gnuradio-howto-${VERSION}
COMMENT=	Documentation on creating GNU Radio signal processing blocks

.include	"../../meta-pkgs/gnuradio/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/distinfo
PATCHDIR=		${.CURDIR}/patches

PY_PATCHPLIST=  yes

REPLACE_PYTHON+=	apps/howto_square.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
