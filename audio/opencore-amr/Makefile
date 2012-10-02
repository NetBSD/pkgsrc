# $NetBSD: Makefile,v 1.2 2012/10/02 23:48:02 asau Exp $
#

DISTNAME=	opencore-amr-0.1.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opencore-amr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencore-amr.sourceforge.net/
COMMENT=	Adaptive Multi-Rate speech codec libraries

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

LICENSE=	apache-2.0

PKGCONFIG_OVERRIDE+=	amrnb/opencore-amrnb.pc.in
PKGCONFIG_OVERRIDE+=	amrwb/opencore-amrwb.pc.in

.include "../../mk/bsd.pkg.mk"
