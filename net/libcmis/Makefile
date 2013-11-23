# $NetBSD: Makefile,v 1.1 2013/11/23 17:11:05 jaapb Exp $

DISTNAME=	libcmis-0.4.1
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcmis/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://libcmis.sourceforge.net/
COMMENT=	Client library for the CMIS interface
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2 OR mpl-1.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-man=no --disable-werror
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes

BUILDLINK_DEPMETHOD.boost-headers?=     build
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
