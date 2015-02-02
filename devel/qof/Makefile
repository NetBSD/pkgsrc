# $NetBSD: Makefile,v 1.21 2015/02/02 02:37:37 mef Exp $

DISTNAME=	qof-0.7.5
PKGREVISION=	17
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qof/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qof.alioth.debian.org/
COMMENT=	Query Object Framework
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	doxygen>=1.8.9.1:../../devel/doxygen

MAKE_JOBS_SAFE=		no

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
