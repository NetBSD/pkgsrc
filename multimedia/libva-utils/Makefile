# $NetBSD: Makefile,v 1.4 2019/12/22 22:27:21 joerg Exp $

DISTNAME=	libva-utils-2.3.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_PROJECT=	libva-utils

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/intel/libva-utils/
COMMENT=	Collection of tests for VA-API
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	automake pkg-config
USE_LANGUAGES=	c c++

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	autogen.sh

SUBST_CLASSES+=		getopt
SUBST_STAGE.getopt=	pre-configure
SUBST_MESSAGE.getopt=	Fixing getopt_long_only
SUBST_FILES.getopt+=	encode/*.c
SUBST_SED.getopt+=	-e 's,getopt_long_only,getopt_long,'

LIBS+=	-lm

.include "../../multimedia/libva/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
