# $NetBSD: Makefile,v 1.10 2004/02/11 01:46:30 abs Exp $

DISTNAME=		dmalloc-5.2.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dmalloc/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.dmalloc.com/
COMMENT=		Run-time configurable debugging malloc library

USE_BUILDLINK2=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shlib
CFLAGS+=		-fPIC -DPIC
CONFIGURE_ARGS+=	--enable-threads

INSTALL_TARGET=		install installinfo

INFO_FILES=		dmalloc.info

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
