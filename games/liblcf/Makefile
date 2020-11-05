# $NetBSD: Makefile,v 1.10 2020/11/05 09:06:53 ryoon Exp $

DISTNAME=	liblcf-0.6.2
PKGREVISION=	2
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

# "We require now the C++ language standard C++14.
# The lowest GCC compiler supporting this fully is GCC5"
GCC_REQD+=	5

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
