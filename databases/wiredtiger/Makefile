# $NetBSD: Makefile,v 1.4 2020/01/26 17:30:54 rillig Exp $

DISTNAME=	wiredtiger-2.7.0
CATEGORIES=	databases
MASTER_SITES=	http://source.wiredtiger.com/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	https://source.wiredtiger.com/
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
