# $NetBSD: Makefile,v 1.12 2004/04/27 03:09:58 snj Exp $

DISTNAME=		dmalloc-5.3.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dmalloc/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.dmalloc.com/
COMMENT=		Run-time configurable debugging malloc library

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shlib
CFLAGS+=		-fPIC -DPIC
CONFIGURE_ARGS+=	--enable-threads

# XXX the "installinfo" target is broken
#INSTALL_TARGET=	install installinfo
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/dmalloc.info ${PREFIX}/info

INFO_FILES=		dmalloc.info

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
