# $NetBSD: Makefile,v 1.45 2003/11/10 17:18:28 agc Exp $

DISTNAME=       xosview-1.8.1alpha
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/

MAINTAINER=	bgrayson@NetBSD.org
HOMEPAGE=	http://xosview.sourceforge.net/
COMMENT=	X11 graphical display of OS statistics

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
