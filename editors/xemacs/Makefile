# $NetBSD: Makefile,v 1.139 2023/01/03 17:37:02 wiz Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	20
COMMENT=	XEmacs text editor version 21.4

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
