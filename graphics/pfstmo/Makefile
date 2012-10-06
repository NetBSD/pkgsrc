# $NetBSD: Makefile,v 1.2 2012/10/06 14:11:13 asau Exp $
#

DISTNAME=	pfstmo-1.3.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfstools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pfstools.sourceforge.net/
COMMENT=	Tone mapping operators for HDR images

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

SUBST_CLASSES+=	ns
SUBST_STAGE.ns=	post-configure
SUBST_FILES.ns=	src/drago03/tmo_drago03.cpp
SUBST_FILES.ns+=src/reinhard05/tmo_reinhard05.cpp
SUBST_FILES.ns+=src/fattal02/tmo_fattal02.cpp
SUBST_FILES.ns+=src/durand02/tmo_durand02.cpp
SUBST_SED.ns=	-e s/_L/LL/g
SUBST_SED.ns+=	-e s/_F/FF/g
SUBST_SED.ns+=	-e s/_R/RR/g
SUBST_SED.ns+=	-e s/_G/GG/g
SUBST_SED.ns+=	-e s/_B/BB/g

.include "options.mk"

.include "../../graphics/pfstools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
