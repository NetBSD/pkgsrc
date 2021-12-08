# $NetBSD: Makefile,v 1.4 2021/12/08 16:01:47 adam Exp $
#

DISTNAME=	libticonv-1.1.3
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tilp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lpg.ticalc.org/prj_tilp/
COMMENT=	Multi-platform linking program for TI graphing calculators
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	ticonv.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
