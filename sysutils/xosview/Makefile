# $NetBSD: Makefile,v 1.11 1998/05/18 09:07:32 tron Exp $
#

DISTNAME=       xosview-1.6.0
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/ \
		http://lore.ece.utexas.edu/~bgrayson/xosview/

MAINTAINER=	bgrayson@ece.utexas.edu

GNU_CONFIGURE=	yes
USE_X11=	yes
MAN1=		xosview.1

MAKE_ENV+=	UVM=${UVM}
MAKE_FLAGS=	ARCH=${ARCH} -f

.include "../../mk/bsd.pkg.mk"
