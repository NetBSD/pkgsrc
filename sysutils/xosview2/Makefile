# $NetBSD: Makefile,v 1.7 2023/11/12 13:23:40 wiz Exp $

DISTNAME=	xosview2-2.3.3
PKGREVISION=	2
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xosview/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://xosview.sourceforge.net/
COMMENT=	X11 graphical display of OS statistics
LICENSE=	gnu-gpl-v2 AND original-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	awk
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17
FORCE_CXX_STD=		c++17

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-xsm

PLIST_SRC=	PLIST.common

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "DragonFly"
PLIST_SRC+=		PLIST.bsd
.elif ${OPSYS} == "Linux"
PLIST_SRC+=		PLIST.linux
CONFIGURE_ARGS+=	--enable-linux-syscalls
.endif

.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
