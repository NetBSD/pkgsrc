# $NetBSD: Makefile,v 1.11 2004/02/15 02:58:46 minskim Exp $

.include "../../editors/xemacs/Makefile.common"

PKGNAME=	xemacs-nox11-21.4.15

MAINTAINER=	magick@NetBSD.org

CONFLICTS=	xemacs-[0-9]*

PLIST_SRC=	${.CURDIR}/../xemacs/PLIST
DISTINFO_FILE=	${.CURDIR}/../xemacs/distinfo
PATCHDIR=	${.CURDIR}/../xemacs/patches

CONFIGURE_ARGS+=	--without-x11	# XXX -nox
CONFIGURE_ARGS+=	--without-jpeg	# XXX -nox
CONFIGURE_ARGS+=	--without-png	# XXX -nox
CONFIGURE_ARGS+=	--without-tiff	# XXX -nox
CONFIGURE_ARGS+=	--without-xpm	# XXX -nox

.include "../../mk/bsd.pkg.mk"
