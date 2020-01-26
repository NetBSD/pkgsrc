# $NetBSD: Makefile,v 1.5 2020/01/26 17:31:24 rillig Exp $
#

DISTNAME=	codec2-0.5.1
CATEGORIES=	ham
MASTER_SITES=	http://files.freedv.org/codec2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	https://rowetel.com/codec2.html
COMMENT=	Speech codec for 2400 bit/s and below

LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c

USE_CMAKE=	yes
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	cd ${WRKSRC} && mkdir build

.include "../../mk/bsd.pkg.mk"
