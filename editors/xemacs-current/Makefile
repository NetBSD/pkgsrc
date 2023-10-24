# $NetBSD: Makefile,v 1.121 2023/10/24 22:09:02 wiz Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	5
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xft2 xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
