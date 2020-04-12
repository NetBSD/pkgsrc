# $NetBSD: Makefile,v 1.6 2020/04/12 08:27:55 adam Exp $

DISTNAME=	liblcf-0.6.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://easyrpg.org/downloads/player/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://easyrpg.org/
COMMENT=	Library to handle RPG Maker 2000/2003 and EasyRPG projects
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes

# Expat in pkgsrc is new enough, however, the version checking fails.
# Remove the version requirement.
SUBST_CLASSES+=		expat
SUBST_STAGE.expat=	pre-configure
SUBST_MESSAGE.expat=	Removing expat version requirement
SUBST_FILES.expat+=	configure
SUBST_SED.expat+=	-e 's|expat >= 2.1|expat|g'

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
