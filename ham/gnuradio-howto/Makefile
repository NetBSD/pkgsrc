# $NetBSD: Makefile,v 1.18 2012/07/02 13:37:39 adam Exp $

DISTNAME=	gr-howto-write-a-block-${VERSION}
PKGREVISION=	6
CATEGORIES=	ham
PKGNAME=	gnuradio-howto-${VERSION}
COMMENT=	Documentation on creating GNU Radio signal processing blocks

PKG_DESTDIR_SUPPORT=	user-destdir

.include	"../../meta-pkgs/gnuradio/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/distinfo
PATCHDIR=		${.CURDIR}/patches

PY_PATCHPLIST=  yes

REPLACE_PYTHON+=	apps/howto_square.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
