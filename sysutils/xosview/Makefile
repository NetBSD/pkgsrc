# $NetBSD: Makefile,v 1.16 1998/09/24 23:15:42 garbled Exp $
#

DISTNAME=       xosview-1.6.0
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/ \
		http://lore.ece.utexas.edu/~bgrayson/xosview/

NOT_FOR_ARCHS=	alpha	# 1.6.2a fixes this, no need to get upset.

MAINTAINER=	bgrayson@ece.utexas.edu
HOMEPAGE=	http://lore.ece.utexas.edu/~bgrayson/xosview.html

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX}
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
