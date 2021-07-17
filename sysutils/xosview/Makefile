# $NetBSD: Makefile,v 1.78 2021/07/17 08:10:48 dholland Exp $

DISTNAME=	xosview-1.22
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=hills/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pogo.org.uk/~mark/xosview/
COMMENT=	X11 graphical display of OS statistics

USE_TOOLS+=	gmake
USE_LANGUAGES=	c gnu++03

AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Linux
MAKE_FLAGS+=	PLATFORM=linux
.elif ${OPSYS} == IRIX
MAKE_FLAGS+=	PLATFORM=irix65
.elif ${OPSYS:M*BSD} || ${OPSYS} == DragonFly
MAKE_FLAGS+=	PLATFORM=bsd
.elif ${OPSYS} == SunOS
MAKE_FLAGS+=	PLATFORM=sunos5
.else
MAKE_FLAGS+=	PLATFORM=gnu
.endif

BUILD_TARGET=		xosview
MAKE_ENV+=		LDLIBS=${LIBS:Q}
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
LIBS.NetBSD+=		-lkvm -lprop
LIBS.FreeBSD+=		-lkvm -ldevstat
LIBS.SunOS+=		-lsocket -lnsl
CPPFLAGS.SunOS+=	-I${X11BASE}/include
ICON_THEMES=		yes

.if ${OPSYS} == "NetBSD"
.  if !defined(UVM) && exists(/usr/include/uvm/uvm.h)
CFLAGS+=	-DUVM
UVM=		yes
BUILD_DEFS+=	UVM
.  endif
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly"
SPECIAL_PERMS+=	bin/xosview ${REAL_ROOT_USER} kmem 2555
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xdefaults ${DESTDIR}${PREFIX}/lib/X11/app-defaults/XOsview

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
