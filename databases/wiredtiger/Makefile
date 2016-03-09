# $NetBSD: Makefile,v 1.2 2016/03/09 10:22:06 fhajny Exp $

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

# WiredTiger only supports x86_64 platforms
ONLY_FOR_PLATFORM=	*-*-x86_64

PKGCONFIG_OVERRIDE+=	build_posix/wiredtiger.pc.in

.include "../../mk/bsd.pkg.mk"
