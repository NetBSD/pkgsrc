# $NetBSD: Makefile,v 1.7 2004/02/10 07:17:38 reed Exp $
#
PKGNAME=		xjed-0.99.16
.include "../jed/Makefile.common"
COMMENT=		Extensible folding editor with Emacs/WordStar/EDT emulations, X11 version

CONFLICTS=		jed-[0-9]*

USE_X11=		yes
CONFIGURE_ARGS+=	--with-x

ALL_TARGET=		xjed

MESSAGE_SRC=		${.CURDIR}/../jed/MESSAGE
PLIST_SRC=		${.CURDIR}/../jed/PLIST
PLIST_SRC+=		${.CURDIR}/PLIST.xjed

.include "../../mk/bsd.pkg.mk"
