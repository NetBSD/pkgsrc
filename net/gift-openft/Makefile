# $NetBSD: Makefile,v 1.3 2004/10/03 00:17:52 tv Exp $
#

DISTNAME=	gift-openft-0.2.1.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gift/}

MAINTAINER=	alex@catbull.com
HOMEPAGE=	http://gift.sourceforge.net/
COMMENT=	OpenFT Plugin for the gift daemon

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

SHLIBTOOL_OVERRIDE=	libtool

LIBS+=${PTHREAD_LDFLAGS} 

.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../net/gift/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
