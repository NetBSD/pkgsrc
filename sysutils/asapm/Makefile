# $NetBSD: Makefile,v 1.1.1.1 1998/12/03 13:35:47 frueauf Exp $
# FreeBSD Id: Makefile,v 1.5 1998/11/29 12:43:12 asami Exp
#

DISTNAME=	asapm-2.3
CATEGORIES=	sysutils x11
MASTER_SITES=	http://bewoner.dma.be/Albert/linux/software/

MAINTAINER=	lamj@stat.cmu.edu
HOMEPAGE=	http://bewoner.dma.be/Albert/linux/

DEPENDS+=	xpm-3.4k:../../graphics/xpm

ONLY_FOR_ARCHS=	i386		# needs apm support

GNU_CONFIGURE=	yes
USE_X11=	yes

INSTALL_TARGET=	install install.man

.include "../../mk/bsd.pkg.mk"
