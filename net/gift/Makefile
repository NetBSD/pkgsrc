# $NetBSD: Makefile,v 1.3 2004/10/03 00:17:51 tv Exp $
#

DISTNAME=	gift-0.11.6
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gift/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	alex@catbull.com
HOMEPAGE=	http://gift.sourceforge.net/
COMMENT=	Modular daemon that abstracts filesharing protocols

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBS+=			${PTHREAD_LDFLAGS}

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/lib/libgift.pc.in

.include "../../devel/libtool/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
