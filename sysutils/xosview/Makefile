# $NetBSD: Makefile,v 1.63 2007/04/09 21:22:11 veego Exp $

DISTNAME=	xosview-1.8.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xosview/}

MAINTAINER=	veego@NetBSD.org
HOMEPAGE=	http://xosview.sourceforge.net/
COMMENT=	X11 graphical display of OS statistics

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_X11BASE=		YES
USE_LANGUAGES=		c c++

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--x-includes=${X11BASE:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE:Q}/lib

INSTALLATION_DIRS=	bin lib/X11/app-defaults ${PKGMANDIR}/man1
MAKE_FLAGS+=		MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if !defined(UVM) && exists(/usr/include/uvm/uvm.h)
CFLAGS+=	-DUVM
UVM=		yes
BUILD_DEFS+=	UVM
.  endif
.elif ${OPSYS} == "SunOS"
USE_TOOLS+=	gmake
CPPFLAGS+=	-I${X11BASE:Q}/include
LIBS+=		-lsocket -lnsl
.endif

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-configure
SUBST_MESSAGE.paths=	Fixing manpage path.
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e s,share/man/man1,${PKGMANDIR}/man1,

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
