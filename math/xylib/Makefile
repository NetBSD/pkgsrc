# $NetBSD: Makefile,v 1.5 2012/09/11 23:04:36 asau Exp $

DISTNAME=	xylib-0.8
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xylib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xylib.sourceforge.net/
COMMENT=	Library for reading powder diffraction data

LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
