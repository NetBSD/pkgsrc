# $NetBSD: Makefile,v 1.6 2001/10/16 13:23:56 tron Exp $

DISTNAME=       sane-frontends-1.0.5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/sane-1.0.5/ \
		ftp://ftp.mostang.com/pub/sane/old-versions/sane-1.0.5/ \
		ftp://gd.tuwien.ac.at/hci/sane/sane-1.0.5/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/sane/sane-1.0.5/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mostang.com/sane/
COMMENT=	Frontends for access to scanners, digitals camera, frame grabbers etc

DEPENDS+=	gimp>=1.0.4:../../graphics/gimp
DEPENDS+=	sane-backends>=1.0.4:../../graphics/sane-backends

CONFLICTS+=	sane<=1.0.3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

# -O to work around a bug with -O2 and egcs.
CFLAGS=		-O
# to find gimp includes
CPPFLAGS=	-I${LOCALBASE}/include

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
