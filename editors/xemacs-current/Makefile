# $NetBSD: Makefile,v 1.94 2018/01/28 20:10:49 wiz Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	1
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

# extra options for x11 support, not for sharing with xemacs-current-nox11

PKG_SUPPORTED_OPTIONS+=		x11 xft xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"
.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
