# $NetBSD: Makefile,v 1.10 2016/12/30 22:25:46 wiz Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs22/:S/-/-nox11-/}
PKGREVISION=	4

CONFLICTS+=	emacs22-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs22/files
PATCHDIR=	${.CURDIR}/../../editors/emacs22/patches
PKGDIR=		${.CURDIR}/../../editors/emacs22

# This needs to be set before including bsd.prefs.mk.
SETGIDGAME=		yes

.include "../../editors/emacs22/Makefile.common"
.include "../../mk/bsd.pkg.mk"
