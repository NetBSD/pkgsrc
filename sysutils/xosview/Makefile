# $NetBSD: Makefile,v 1.55 2005/12/05 20:51:02 rillig Exp $

DISTNAME=	xosview-1.8.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xosview/}

MAINTAINER=	bgrayson@NetBSD.org
HOMEPAGE=	http://xosview.sourceforge.net/
COMMENT=	X11 graphical display of OS statistics

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_X11BASE=		YES
USE_LANGUAGES=		c++

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib

INSTALLATION_DIRS=	bin lib/X11/app-defaults man/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if !defined(UVM) && exists(/usr/include/uvm/uvm.h)
CFLAGS+=	-DUVM
UVM=		# defined
BUILD_DEFS+=	UVM
.  endif
.elif ${OPSYS} == "SunOS"
USE_TOOLS+=	gmake
CPPFLAGS+=	-I${X11BASE}/include
LIBS+=		-lsocket -lnsl
.endif

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
