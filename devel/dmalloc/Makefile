# $NetBSD: Makefile,v 1.25 2023/02/11 10:19:18 fcambus Exp $

DISTNAME=		dmalloc-5.5.2
PKGREVISION=		1
CATEGORIES=		devel
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dmalloc/}
MASTER_SITES=		https://dmalloc.com/releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://dmalloc.com/
COMMENT=		Run-time configurable debugging malloc library

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shlib
CFLAGS+=		-fPIC -DPIC
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--enable-cxx

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_TARGET=		install installcxx
TEST_TARGET=		heavy

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
