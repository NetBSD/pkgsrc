# $NetBSD: Makefile,v 1.12 2004/02/15 03:01:57 minskim Exp $

.include "../../editors/xemacs/Makefile.common"

PKGNAME=	${DISTNAME:S/xemacs/xemacs-nox11/}

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
