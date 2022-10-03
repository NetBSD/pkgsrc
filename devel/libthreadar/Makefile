# $NetBSD: Makefile,v 1.1 2022/10/03 13:47:20 nros Exp $

DISTNAME=	libthreadar-1.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libthreadar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libthreadar.sf.net/
COMMENT=	C++ library to manage threads
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	src/libthreadar.pc.tmpl.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
