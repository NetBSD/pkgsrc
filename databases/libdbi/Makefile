# $NetBSD: Makefile,v 1.1.1.1 2010/03/10 23:55:48 wiz Exp $
#

DISTNAME=	libdbi-0.8.3
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdbi/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://libdbi.sourceforge.net/
COMMENT=	Database Independent Abstraction Layer for C
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--disable-docs

AUTO_MKDIRS=		yes

.include "../../mk/bsd.pkg.mk"
