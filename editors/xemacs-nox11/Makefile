# $NetBSD: Makefile,v 1.21 2012/10/03 11:43:47 asau Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}

FILESDIR=	${.CURDIR}/../../editors/xemacs/files
PATCHDIR=	${.CURDIR}/../../editors/xemacs/patches
PKGDIR=		${.CURDIR}/../../editors/xemacs

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.xemacs+=	-x11 -lucid
#PKG_OPTIONS.xemacs+=	-gtk -motif -xaw

.include "../../editors/xemacs/Makefile"
