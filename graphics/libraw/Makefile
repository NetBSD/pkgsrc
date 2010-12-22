# $NetBSD: Makefile,v 1.6 2010/12/22 16:02:18 gls Exp $
#

DISTNAME=		LibRaw-0.12.1
PKGNAME=		${DISTNAME:tl}
CATEGORIES=		graphics
MASTER_SITES=	http://www.libraw.org/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libraw.org/
COMMENT=	Raw decoding/processing library
LICENSE=	gnu-lgpl-v2.1 OR cddl-1.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=		pkg-config gmake
MAKE_JOBS_SAFE=	no

PKGCONFIG_OVERRIDE+=	libraw.pc.in
PKGCONFIG_OVERRIDE+=	libraw_r.pc.in

.include "../../graphics/lcms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
