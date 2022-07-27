# $NetBSD: Makefile,v 1.34 2022/07/27 18:35:30 wiz Exp $

DISTNAME=	libmatchbox-1.9
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	http://downloads.yoctoproject.org/releases/matchbox/libmatchbox/1.9/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.yoctoproject.org/tools-resources/projects/matchbox/
COMMENT=	Library for matchbox window manager for computers with small displays
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		pc
SUBST_SED.pc+=		-e "s/libpng12/libpng16/"
SUBST_FILES.pc+=	configure
SUBST_STAGE.pc=		pre-configure
SUBST_MESSAGE.pc=	Fix png library name.

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
