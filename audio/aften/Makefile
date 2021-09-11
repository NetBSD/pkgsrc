# $NetBSD: Makefile,v 1.1 2021/09/11 23:44:48 nia Exp $

DISTNAME=	aften-0.0.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aften/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aften.sourceforge.net/
COMMENT=	ATSC A/52 / AC-3 / Dolby Digital audio encoder
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DBINDINGS_CXX=ON
CMAKE_ARGS+=	-DSHARED=ON

pre-configure:
	mkdir ${WRKSRC}/build

.include "../../mk/bsd.pkg.mk"
