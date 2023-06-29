# $NetBSD: Makefile,v 1.118 2023/06/29 20:57:44 hauke Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	3
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xft xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
