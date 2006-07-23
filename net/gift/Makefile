# $NetBSD: Makefile,v 1.11 2006/07/23 22:14:26 tv Exp $
#

DISTNAME=	gift-0.11.8.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gift/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	alex@catbull.com
HOMEPAGE=	http://gift.sourceforge.net/
COMMENT=	Modular daemon that abstracts filesharing protocols

USE_TOOLS+=		perl:run pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PTHREAD_AUTO_VARS=	yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/lib/libgift.pc.in

.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
