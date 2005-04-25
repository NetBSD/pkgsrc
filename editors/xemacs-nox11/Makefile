# $NetBSD: Makefile,v 1.14 2005/04/25 17:23:50 magick Exp $

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
CONFIGURE_ARGS+=	--site-includes=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--site-libraries=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--site-runtime-libraries=${LOCALBASE}/lib

PLIST_SUBST+=	X11ONLY="@comment "

.include "../../mk/bsd.pkg.mk"
