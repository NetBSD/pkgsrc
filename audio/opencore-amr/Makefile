# $NetBSD: Makefile,v 1.1.1.1 2010/04/16 15:42:10 reed Exp $
#

DISTNAME=	opencore-amr-0.1.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opencore-amr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencore-amr.sourceforge.net/
COMMENT=	Adaptive Multi-Rate speech codec libraries

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

LICENSE=	apache-2.0

PKGCONFIG_OVERRIDE+=	amrnb/opencore-amrnb.pc.in
PKGCONFIG_OVERRIDE+=	amrwb/opencore-amrwb.pc.in

.include "../../mk/bsd.pkg.mk"
