# $NetBSD: Makefile,v 1.7 2008/06/20 01:09:22 joerg Exp $

DISTNAME=	opendis-0.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://ods.sourceforge.net/dl/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://ods.sourceforge.net/
COMMENT=	Download images from Flashpoint Digita-based cameras

PKG_DESTDIR_SUPPORT=	user-destdir

#USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
