# $NetBSD: Makefile,v 1.9 2016/04/20 12:10:33 nros Exp $
#

DISTNAME=	twolame-0.3.13
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=twolame/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.twolame.org/
COMMENT=	Optimised MPEG Audio Layer 2 (MP2) encoder based on tooLAME
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	twolame.pc.in

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
