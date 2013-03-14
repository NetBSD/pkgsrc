# $NetBSD: Makefile,v 1.71 2013/03/14 15:11:11 wiz Exp $

DISTNAME=	xosview-1.8.3
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xosview/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pogo.org.uk/~mark/xosview/
COMMENT=	X11 graphical display of OS statistics

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_X11BASE=		YES
USE_LANGUAGES=		c c++

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib

INSTALLATION_DIRS=	bin lib/X11/app-defaults ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	PREFIX_TO_USE=${DESTDIR}${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if !defined(UVM) && exists(/usr/include/uvm/uvm.h)
CFLAGS+=	-DUVM
UVM=		yes
BUILD_DEFS+=	UVM
.  endif
.elif ${OPSYS} == "SunOS"
USE_TOOLS+=	gmake
CPPFLAGS+=	-I${X11BASE}/include
LIBS+=		-lsocket -lnsl
.elif ${OPSYS} == "Linux"
USE_TOOLS+=	gmake
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly"
SPECIAL_PERMS+=	bin/xosview ${REAL_ROOT_USER} kmem 2555
.endif

SUBST_CLASSES+=		unpriv
SUBST_STAGE.unpriv=	pre-configure
SUBST_FILES.unpriv=	config/Makefile.top.in
SUBST_SED.unpriv=	-e s,@INSTALL_ARGS@,,

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-configure
SUBST_MESSAGE.paths=	Fixing manpage path.
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e s,share/man/man1,${PKGMANDIR}/man1,

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
