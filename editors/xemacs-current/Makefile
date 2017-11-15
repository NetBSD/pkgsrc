# $NetBSD: Makefile,v 1.92 2017/11/15 14:46:31 hauke Exp $

PKGNAME=	${DISTNAME}
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

# extra options for x11 support, not for sharing with xemacs-current-nox11

PKG_SUPPORTED_OPTIONS+=		x11 xft xface
PKG_SUGGESTED_OPTIONS+=		x11 xft

.include "options.mk"
.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
