# $NetBSD: Makefile,v 1.4 2016/12/30 23:09:41 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV} (no X11 support)
PKGREVISION=	23

CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-png
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--with-site-prefixes=${PREFIX}
CONFIGURE_ARGS+=	--with-site-runtime-libraries=${PREFIX}/lib

.include "../../editors/xemacs-current/options.mk"
.include "../../editors/xemacs-current/Makefile.common"
.include "../../mk/bsd.pkg.mk"
