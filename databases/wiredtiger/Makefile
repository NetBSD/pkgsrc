# $NetBSD: Makefile,v 1.1 2016/02/26 15:52:08 fhajny Exp $

DISTNAME=	wiredtiger-2.7.0
CATEGORIES=	databases
MASTER_SITES=	http://source.wiredtiger.com/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://source.wiredtiger.com/
COMMENT=	Open Source extensible platform for data management
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "options.mk"

PKGCONFIG_OVERRIDE+=	build_posix/wiredtiger.pc.in

.include "../../mk/bsd.pkg.mk"
