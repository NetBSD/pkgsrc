# $NetBSD: Makefile,v 1.1 2015/04/19 17:29:21 rodent Exp $

DISTNAME=	libsbsms-2.0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sbsms/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://sbsms.sourceforge.net/
COMMENT=	Subband Sinusoidal Modeling Synthesis
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	sbsms.pc.in
CONFIGURE_ARGS+=	--enable-shared=yes

.include "../../mk/bsd.pkg.mk"
