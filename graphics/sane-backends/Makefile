# $NetBSD: Makefile,v 1.6 2001/10/15 21:27:17 veego Exp $

DISTNAME=       sane-backends-1.0.5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/ \
		ftp://ftp.mostang.com/pub/sane/old-versions/ \
		ftp://gd.tuwien.ac.at/hci/sane/ \
		${MASTER_SITE_SUNSITE:=apps/graphics/capture/} \
		${MASTER_SITE_SUNSITE:=Incoming/} \
		ftp://ftp.u-aizu.ac.jp/pub/misc/device/scsi/scanner/sane/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/sane/

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
