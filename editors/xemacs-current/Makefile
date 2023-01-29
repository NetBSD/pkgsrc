# $NetBSD: Makefile,v 1.114 2023/01/29 21:15:58 ryoon Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	21
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xft xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
