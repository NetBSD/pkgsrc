# $NetBSD: Makefile,v 1.6 2003/04/05 21:40:54 wiz Exp $
#
PKGNAME=		xjed-0.99.16
.include "../jed/Makefile.common"
COMMENT=		Extensible folding editor with Emacs/WordStar/EDT emulations, X11 version

CONFLICTS=		jed-[0-9]*

USE_X11=		yes
CONFIGURE_ARGS+=	--with-x

ALL_TARGET=		xjed

MESSAGE=		${.CURDIR}/../jed/MESSAGE
PLIST_SRC=		${.CURDIR}/../jed/PLIST
PLIST_SRC+=		${.CURDIR}/PLIST.xjed

.include "../../mk/bsd.pkg.mk"
