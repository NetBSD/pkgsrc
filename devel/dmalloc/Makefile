# $NetBSD: Makefile,v 1.21 2010/02/11 18:35:07 drochner Exp $

DISTNAME=		dmalloc-5.5.2
CATEGORIES=		devel
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dmalloc/}
MASTER_SITES=		http://dmalloc.com/releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dmalloc.com/
COMMENT=		Run-time configurable debugging malloc library

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shlib
CFLAGS+=		-fPIC -DPIC
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--enable-cxx

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_TARGET=	install installcxx
TEST_TARGET=	heavy

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
