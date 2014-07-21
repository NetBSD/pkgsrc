# $NetBSD: Makefile,v 1.1 2014/07/21 07:30:50 dbj Exp $
#

DISTNAME=	codec2-0.3.0.1698
WRKSRC=		${WRKDIR}/codec2
CATEGORIES=	ham
# svn://svn.code.sf.net/p/freetel/code/codec2-dev
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	http://rowetel.com/codec2.html
COMMENT=	Speech codec for 2400 bit/s and below

LICENSE=	gnu-lgpl-v2.1

# This package doesn't really use c++, but cmake probes for it
# causing the configure to fail unless we declare it here.  Maybe
# there is a way to tell cmake to not require c++
USE_LANGUAGES=	c c++

USE_CMAKE=yes
CONFIGURE_DIRS=build
CMAKE_ARG_PATH=..

pre-configure:
	cd ${WRKSRC} && mkdir build

.include "../../mk/bsd.pkg.mk"
