# $NetBSD: Makefile,v 1.37 2000/05/17 10:26:36 tron Exp $

DISTNAME=	netpbm-9.2
CATEGORIES=	graphics
MASTER_SITES=	http://download.sourceforge.net/netpbm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://netpbm.sourceforge.net/info

DEPENDS+=	tiff>=3.5.4:../../graphics/tiff
DEPENDS+=	png>=1.0.6:../../graphics/png

USE_GMAKE=	yes
USE_LIBTOOL=	yes

INSTALL_TARGET=	install.dev install
MAKE_ENV+=	ECHO="${ECHO}"
MAKEFILE=	GNUmakefile

.include "../../mk/bsd.pkg.mk"
