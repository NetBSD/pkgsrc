# $NetBSD: Makefile,v 1.5 2020/03/20 11:57:49 nia Exp $

DISTNAME=	gts-0.7.6
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gts/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gts.sourceforge.net/
COMMENT=	GNU Triangulated Surface Library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
# it is not necessary to configure libtool
CONFIGURE_ARGS+=	--with-tags=""
PKGCONFIG_OVERRIDE+=	gts.pc.in

CPPFLAGS+=	-I${BUILDLINK_PREFIX.netpbm}/include/netpbm

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
