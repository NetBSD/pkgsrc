# $NetBSD: Makefile,v 1.1 2021/05/17 10:01:31 thor Exp $

DISTNAME=	laszip-src-3.4.3
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=LASzip/}
GITHUB_PROJECT=	LASzip
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://laszip.org/
COMMENT=	Free and lossless LiDAR compression
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
