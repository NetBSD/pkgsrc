# $NetBSD: Makefile,v 1.13 1998/05/29 21:20:55 tron Exp $
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

.include "../../mk/bsd.pkg.mk"
