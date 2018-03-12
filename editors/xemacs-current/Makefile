# $NetBSD: Makefile,v 1.97 2018/03/12 11:16:25 wiz Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	5
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

# extra options for x11 support, not for sharing with xemacs-current-nox11
# Version information in ../../editors/xemacs-current/Makefile.common

PKG_SUPPORTED_OPTIONS+=		x11 xft xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"
.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
