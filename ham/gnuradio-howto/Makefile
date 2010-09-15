# $NetBSD: Makefile,v 1.12 2010/09/15 09:38:44 markd Exp $

DISTNAME=	gr-howto-write-a-block-${VERSION}
CATEGORIES=	ham
PKGNAME=	gnuradio-howto-${VERSION}
COMMENT=	Documentation on creating GNU Radio signal processing blocks

PKG_DESTDIR_SUPPORT=	user-destdir

.include	"../../meta-pkgs/gnuradio/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/distinfo
PATCHDIR=		${.CURDIR}/patches

PY_PATCHPLIST=  yes

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
