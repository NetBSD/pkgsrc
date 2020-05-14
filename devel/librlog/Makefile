# $NetBSD: Makefile,v 1.6 2020/05/14 19:08:06 joerg Exp $
#

DISTNAME=	rlog-1.3.7
PKGNAME=	lib${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://arg0.net/vgough/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.arg0.net/rlog
COMMENT=	C++ logging library

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	librlog.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
