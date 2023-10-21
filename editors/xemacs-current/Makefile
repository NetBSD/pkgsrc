# $NetBSD: Makefile,v 1.120 2023/10/21 17:10:07 gdt Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	4
COMMENT=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xft2 xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
