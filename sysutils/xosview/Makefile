# $NetBSD: Makefile,v 1.12 1998/05/29 17:57:29 tron Exp $
#

DISTNAME=       xosview-1.6.0
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/ \
		http://lore.ece.utexas.edu/~bgrayson/xosview/

MAINTAINER=	bgrayson@ece.utexas.edu

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX}
USE_X11=	yes
MAN1=		xosview.1

MAKE_ENV+=	UVM=${UVM}
MAKE_FLAGS=	ARCH=${ARCH} -f

.include "../../mk/bsd.pkg.mk"
