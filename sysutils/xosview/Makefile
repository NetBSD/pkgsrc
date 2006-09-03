# $NetBSD: Makefile,v 1.60 2006/09/03 00:56:30 wiz Exp $

DISTNAME=	xosview-1.8.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xosview/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xosview.sourceforge.net/
COMMENT=	X11 graphical display of OS statistics

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_X11BASE=		YES
USE_LANGUAGES=		c c++

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--x-includes=${X11BASE:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE:Q}/lib

INSTALLATION_DIRS=	bin lib/X11/app-defaults man/man1
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

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
