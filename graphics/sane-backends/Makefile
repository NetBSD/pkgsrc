# $NetBSD: Makefile,v 1.7 2001/10/16 13:17:04 tron Exp $

DISTNAME=       sane-backends-1.0.5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/sane-1.0.5/ \
		ftp://ftp.mostang.com/pub/sane/old-versions/sane-1.0.5/ \
		ftp://gd.tuwien.ac.at/hci/sane/sane-1.0.5/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/sane/sane-1.0.5/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mostang.com/sane/
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

DEPENDS+=	jpeg-6b:../../graphics/jpeg

CONFLICTS+=	sane<=1.0.3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
CPPFLAGS+=	-I${PREFIX}/include

# -O to work around a bug with -O2 and egcs.
CFLAGS=		-O -I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
