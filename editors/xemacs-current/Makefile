# $NetBSD: Makefile,v 1.117 2023/06/20 20:45:42 hauke Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	2
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xft xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
