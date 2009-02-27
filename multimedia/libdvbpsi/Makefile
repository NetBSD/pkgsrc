# $NetBSD: Makefile,v 1.8 2009/02/27 22:38:16 wiz Exp $

DISTNAME=	libdvbpsi5-0.1.6
PKGNAME=	${DISTNAME:S/5-/-/}
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvbpsi/0.1.6/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.videolan.org/
COMMENT=	PSI decoder and generator library for MPEG2 and DVB streams

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
