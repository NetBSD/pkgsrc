# $NetBSD: Makefile,v 1.9 2001/10/19 21:31:09 jlam Exp $

DISTNAME=       sane-backends-1.0.5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/sane-1.0.5/ \
		ftp://ftp.mostang.com/pub/sane/old-versions/sane-1.0.5/ \
		ftp://gd.tuwien.ac.at/hci/sane/sane-1.0.5/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/sane/sane-1.0.5/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mostang.com/sane/
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc.

CONFLICTS+=	sane<=1.0.3

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/libusb/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# -O to work around a bug with -O2 and egcs.
CFLAGS+=	-O
