# $NetBSD: Makefile,v 1.19 2012/08/29 11:22:15 obache Exp $

DISTNAME=	gr-howto-write-a-block-${VERSION}
PKGREVISION=	7
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
