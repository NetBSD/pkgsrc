# $NetBSD: Makefile,v 1.3 2012/07/28 21:23:17 reed Exp $
#

DISTNAME=	rlog-1.3.7
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://arg0.net/vgough/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.arg0.net/rlog
COMMENT=	C++ logging library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	librlog.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
