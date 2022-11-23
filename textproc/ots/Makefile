# $NetBSD: Makefile,v 1.10 2022/11/23 16:21:11 adam Exp $

DISTNAME=	ots-0.5.0
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	http://downloads.sf.net/project/libots/libots/${DISTNAME}/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://libots.sf.net/
COMMENT=	Tool and library for auto-summarizing text
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
MAKE_JOBS_SAFE=	no

PKGCONFIG_OVERRIDE+=	libots-1.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
