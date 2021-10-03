# $NetBSD: Makefile,v 1.111 2021/10/03 17:53:11 hauke Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	18
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xft xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
