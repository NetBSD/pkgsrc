# $NetBSD: Makefile,v 1.141 2023/10/24 22:09:02 wiz Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	22
COMMENT=	XEmacs text editor version 21.4

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
