# $NetBSD: Makefile,v 1.4 2001/02/16 15:22:28 wiz Exp $

DISTNAME=	opendis-0.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://ods.sourceforge.net/dl/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://ods.sourceforge.net/
COMMENT=	Download images from Flashpoint Digita-based cameras

#USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
