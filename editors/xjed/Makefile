# $NetBSD: Makefile,v 1.15 2012/08/07 14:54:36 marino Exp $
#
PKGNAME=		xjed-0.99.16
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../editors/jed/Makefile.common"
COMMENT=		Extensible folding editor with Emacs/WordStar/EDT emulations, X11 version

CONFLICTS=		jed-[0-9]*

CONFIGURE_ARGS+=	--with-x

BUILD_TARGET=		xjed

MESSAGE_SRC=		${.CURDIR}/../jed/MESSAGE
PLIST_SRC=		${.CURDIR}/../jed/PLIST
PLIST_SRC+=		${.CURDIR}/PLIST.xjed

.include "../../mk/bsd.prefs.mk"

# XXX For just now disable grantpt(3) for NetBSD-2.0F and later
# Also for Dragonfly, there's no strops.h header
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
CONFIGURE_ENV+=		ac_cv_func_grantpt=no
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
