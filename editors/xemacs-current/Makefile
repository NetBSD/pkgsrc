# $NetBSD: Makefile,v 1.127 2026/10/06 09:31:11 hauke Exp $

PKGNAME=	${DISTNAME}
COMMENT=	The XEmacs text editor version ${PKGVERSION_NOREV}

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xft2 xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
