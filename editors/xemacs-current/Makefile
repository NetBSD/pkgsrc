# $NetBSD: Makefile,v 1.91 2016/12/30 23:18:53 wiz Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	23
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

# extra options for x11 support, not for sharing with xemacs-current-nox11

PKG_SUPPORTED_OPTIONS+=		x11 xft
PKG_OPTIONS_OPTIONAL_GROUPS=	toolkit
PKG_OPTIONS_GROUP.toolkit=	gtk lucid motif
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
