# $NetBSD: Makefile,v 1.11 2012/03/03 00:11:54 wiz Exp $
#

DISTNAME=	qof-0.7.5
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qof/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qof.alioth.debian.org/
COMMENT=	Query Object Framework

BUILD_DEPENDS+=	doxygen>=1.6.3:../../devel/doxygen

MAKE_JOBS_SAFE=		no

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	qof-1.pc.in
PKGCONFIG_OVERRIDE+=	qof.pc.in

# not portable enough
BUILDLINK_TRANSFORM+=	rm:-Werror

# optional
#.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
