# $NetBSD: Makefile,v 1.1.1.1 2007/02/18 14:18:18 xtraeme Exp $
#

DISTNAME=	rlog-1.3.7
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://arg0.net/vgough/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arg0.net/wiki/rlog
COMMENT=	C++ logging library

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	librlog.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
