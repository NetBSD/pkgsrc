# $NetBSD: Makefile,v 1.2 2021/10/03 17:31:23 tnn Exp $

DISTNAME=	log4cpp-1.1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=log4cpp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://log4cpp.sourceforge.net/
COMMENT=	C++ logging library
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/log4cpp
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-doxygen
PKGCONFIG_OVERRIDE+=	log4cpp.pc.in

.include "../../mk/bsd.pkg.mk"
