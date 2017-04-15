# $NetBSD: Makefile,v 1.5 2017/04/15 09:49:53 adam Exp $

DISTNAME=	opencore-amr-0.1.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opencore-amr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencore-amr.sourceforge.net/
COMMENT=	Adaptive Multi-Rate speech codec libraries
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	amrnb/opencore-amrnb.pc.in
PKGCONFIG_OVERRIDE+=	amrwb/opencore-amrwb.pc.in

.include "../../mk/bsd.pkg.mk"
