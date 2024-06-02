# $NetBSD: Makefile,v 1.19 2024/06/02 12:28:01 ryoon Exp $

DISTNAME=	liblcf-0.7.0
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	https://easyrpg.org/downloads/player/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://easyrpg.org/
COMMENT=	Library to handle RPG Maker 2000/2003 and EasyRPG projects
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES+=	c c++
FORCE_CXX_STD=	c++17
USE_LIBTOOL=	yes

# Expat in pkgsrc is new enough, however, the version checking fails.
# Remove the version requirement.
SUBST_CLASSES+=		expat
SUBST_STAGE.expat=	pre-configure
SUBST_MESSAGE.expat=	Removing expat version requirement
SUBST_FILES.expat+=	configure
SUBST_SED.expat+=	-e 's|expat >= 2.1|expat|g'

PKGCONFIG_OVERRIDE+=	builds/liblcf.pc.in

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
