# $NetBSD: Makefile,v 1.9 2004/12/03 15:14:56 wiz Exp $
#
PKGNAME=		xjed-0.99.16
.include "../jed/Makefile.common"
COMMENT=		Extensible folding editor with Emacs/WordStar/EDT emulations, X11 version

CONFLICTS=		jed-[0-9]*

USE_X11=		yes
CONFIGURE_ARGS+=	--with-x

BUILD_TARGET=		xjed

MESSAGE_SRC=		${.CURDIR}/../jed/MESSAGE
PLIST_SRC=		${.CURDIR}/../jed/PLIST
PLIST_SRC+=		${.CURDIR}/PLIST.xjed

.include "../../mk/bsd.prefs.mk"

# XXX For just now disable grantpt(3) for NetBSD-2.0F and later
.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		ac_cv_func_grantpt=no
.endif

.include "../../mk/bsd.pkg.mk"
