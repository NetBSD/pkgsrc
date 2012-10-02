# $NetBSD: Makefile,v 1.3 2012/10/02 21:25:20 asau Exp $
#

DISTNAME=	libdbi-0.8.3
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdbi/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://libdbi.sourceforge.net/
COMMENT=	Database Independent Abstraction Layer for C
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--disable-docs

AUTO_MKDIRS=		yes

.include "../../mk/bsd.pkg.mk"
