# $NetBSD: Makefile,v 1.9 2002/08/19 19:18:31 mycroft Exp $

.include "../../graphics/sane-backends/Makefile.common"

DISTNAME=       sane-frontends-${SANE_VERSION}

COMMENT=	Frontends for access to scanners, digitals camera, frame grabbers etc

DEPENDS+=	gimp>=1.0.4:../../graphics/gimp
BUILDLINK_DEPENDS.sane=	sane-backends-${SANE_VERSION}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

# -O to work around a bug with -O2 and egcs.
CFLAGS=		-O
# to find gimp includes
CPPFLAGS=	-I${LOCALBASE}/include

.include "../../graphics/sane-backends/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
