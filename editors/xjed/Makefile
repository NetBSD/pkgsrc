# $NetBSD: Makefile,v 1.18 2023/12/19 23:57:55 gdt Exp $
#
PKGNAME=		xjed-0.99.19
PKGREVISION=		1
LICENSE=		gnu-gpl-v2

.include "../../editors/jed/Makefile.common"
COMMENT=		Extensible folding editor + Emacs/WordStar/EDT emulations, X11 version

CONFLICTS=		jed-[0-9]*

CONFIGURE_ARGS+=	--with-x

BUILD_TARGET=		xjed

MESSAGE_SRC=		${.CURDIR}/../../editors/jed/MESSAGE
PLIST_SRC=		${.CURDIR}/../../editors/jed/PLIST
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
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
