# $NetBSD: Makefile,v 1.19 2012/10/13 01:35:43 obache Exp $
#

DISTNAME=	m17n-lib-1.6.2
PKGREVISION=	4
CATEGORIES=	devel converters editors inputmethod textproc time
MASTER_SITES=	http://www.m17n.org/m17n-lib-download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/m17n/
COMMENT=	Multilingualization library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	m17n-core.pc.in m17n-shell.pc.in m17n-flt.pc.in
PKGCONFIG_OVERRIDE+=	m17n-gui.pc.in

.include "options.mk"

.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../misc/m17n-db/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
