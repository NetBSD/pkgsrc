# $NetBSD: Makefile,v 1.22 2016/04/13 13:54:30 hauke Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}

FILESDIR=	${.CURDIR}/../../editors/xemacs/files
PATCHDIR=	${.CURDIR}/../../editors/xemacs/patches
PKGDIR=		${.CURDIR}/../../editors/xemacs

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS.xemacs+=	-x11

.include "../../editors/xemacs/Makefile"
