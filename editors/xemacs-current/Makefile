# $NetBSD: Makefile,v 1.116 2023/05/24 11:40:11 hauke Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	1
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xft xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
