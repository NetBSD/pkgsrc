# $NetBSD: Makefile,v 1.4 2016/08/21 19:14:07 fhajny Exp $
#

DISTNAME=	libdbi-0.9.0
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdbi/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://libdbi.sourceforge.net/
COMMENT=	Database Independent Abstraction Layer for C
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--disable-docs

AUTO_MKDIRS=		yes

.include "../../mk/bsd.pkg.mk"
