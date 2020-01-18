# $NetBSD: Makefile,v 1.21 2020/01/18 23:33:15 rillig Exp $

DISTNAME=	gift-openft-0.2.1.6
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gift/}

MAINTAINER=	alex@catbull.com
HOMEPAGE=	https://gift.sourceforge.net/
COMMENT=	OpenFT Plugin for the gift daemon

BDB_ACCEPTED=		db4 db5
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PTHREAD_AUTO_VARS=	yes
SHLIBTOOL_OVERRIDE=	# empty

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/gift/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
