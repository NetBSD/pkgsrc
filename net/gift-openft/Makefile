# $NetBSD: Makefile,v 1.8 2006/01/06 15:10:06 wiz Exp $
#

DISTNAME=	gift-openft-0.2.1.3
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gift/}

MAINTAINER=	alex@catbull.com
HOMEPAGE=	http://gift.sourceforge.net/
COMMENT=	OpenFT Plugin for the gift daemon

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PTHREAD_AUTO_VARS=	yes
SHLIBTOOL_OVERRIDE=	libtool

.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../net/gift/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
