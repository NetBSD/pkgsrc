# $NetBSD: Makefile,v 1.22 2013/11/20 13:23:44 obache Exp $

DISTNAME=	gr-howto-write-a-block-${VERSION}
PKGREVISION=	9
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
