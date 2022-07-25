# $NetBSD: Makefile,v 1.3 2022/07/25 11:12:29 wiz Exp $

DISTNAME=	log4cpp-1.1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=log4cpp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://log4cpp.sourceforge.net/
COMMENT=	C++ logging library
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/log4cpp
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-doxygen
PKGCONFIG_OVERRIDE+=	log4cpp.pc.in

.include "../../mk/bsd.pkg.mk"
