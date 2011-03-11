# $NetBSD: Makefile,v 1.3 2011/03/11 12:57:46 drochner Exp $

DISTNAME=	xylib-0.8
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xylib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xylib.sourceforge.net/
COMMENT=	Library for reading powder diffraction data

LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
