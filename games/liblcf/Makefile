# $NetBSD: Makefile,v 1.1 2018/12/21 16:56:18 nia Exp $

DISTNAME=	liblcf-0.5.4
CATEGORIES=	games
MASTER_SITES=	https://easyrpg.org/downloads/player/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://easyrpg.org/
COMMENT=	Library to handle RPG Maker 2000/2003 and EasyRPG projects
LICENSE=	mit

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
