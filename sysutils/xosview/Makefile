# $NetBSD: Makefile,v 1.46 2003/11/11 07:57:42 wiz Exp $

DISTNAME=	xosview-1.8.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xosview/}

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
