# $NetBSD: Makefile,v 1.3 2020/10/12 21:52:02 bacon Exp $

DISTNAME=	harmgen-3.1.3
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://flaterco.com/files/xtide/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flaterco.com/
COMMENT=	Program to derive harmonic constants from water level observations
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS=	bash gmake gsed
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../math/octave/buildlink3.mk"
.include "../../math/congen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
