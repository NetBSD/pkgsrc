# $NetBSD: Makefile,v 1.9 1998/04/15 10:38:50 agc Exp $
#

DISTNAME=       xosview-1.5.1
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/

MAINTAINER=	bgrayson@ece.utexas.edu

GNU_CONFIGURE=	yes
USE_X11=	yes
MAN1=		xosview.1

MAKE_ENV+=	UVM=${UVM}
MAKE_FLAGS=	ARCH=${ARCH} -f

.include "../../mk/bsd.pkg.mk"
