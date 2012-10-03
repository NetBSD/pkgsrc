# $NetBSD: Makefile,v 1.3 2012/10/03 11:43:47 asau Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}

FILESDIR=	${.CURDIR}/../../editors/xemacs-current/files
PATCHDIR=	${.CURDIR}/../../editors/xemacs-current/patches
PKGDIR=		${.CURDIR}/../../editors/xemacs-current

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.xemacs+=	-x11 -xft -gtk -lucid -motif

.include "../../editors/xemacs-current/Makefile"
