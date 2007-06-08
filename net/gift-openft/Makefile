# $NetBSD: Makefile,v 1.12 2007/06/08 12:25:05 wiz Exp $
#

DISTNAME=	gift-openft-0.2.1.6
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gift/}

MAINTAINER=	alex@catbull.com
HOMEPAGE=	http://gift.sourceforge.net/
COMMENT=	OpenFT Plugin for the gift daemon

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

PTHREAD_AUTO_VARS=	yes
SHLIBTOOL_OVERRIDE=	# empty

.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../net/gift/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
