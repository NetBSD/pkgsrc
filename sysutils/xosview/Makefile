# $NetBSD: Makefile,v 1.41 2002/12/04 13:25:31 tron Exp $

DISTNAME=       xosview-1.7.0.b
PKGNAME=	xosview-1.7.0b
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/ \
		http://lore.ece.utexas.edu/~bgrayson/xosview/

MAINTAINER=	bgrayson@netbsd.org
HOMEPAGE=	http://lore.ece.utexas.edu/~bgrayson/xosview.html
COMMENT=	X11 graphical display of OS statistics

NOT_FOR_PLATFORM=	NetBSD-1.6[H-Z]*-* NetBSD-1.[7-9]*-* NetBSD-[2-9]*-*

USE_BUILDLINK2=		YES
USE_X11BASE=		YES

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if !defined(UVM) && exists(/usr/include/uvm/uvm.h)
CFLAGS+=	-DUVM
UVM=		# defined
BUILD_DEFS=	UVM
.  endif
.elif ${OPSYS} == "SunOS"
USE_GMAKE=	YES
BUILD_DEPENDS+=	egcs-1.1.2:../../lang/egcs
CXX=		${LOCALBASE}/egcs/bin/g++
CPPFLAGS+=	-I${X11BASE}/include
LIBS+=		-lsocket -lnsl
.endif

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
