# $NetBSD: Makefile,v 1.4 2002/08/01 05:48:19 jlam Exp $

DISTNAME=		ntop-2.1
PKGNAME=		ntop2-2.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ntop/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ntop.org/
COMMENT=		shows network usage (similar to "top" for processes)

CONFLICTS=		ntop-[0-9]*

WRKSRC=                 ${WRKDIR}/ntop

USE_GMAKE=		yes
GNU_CONFIGURE=          yes
# --enable-micro-ntop causes compile to fail 
CONFIGURE_ARGS+=	--disable-mysql
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK_ONLY=	yes

PTHREAD_OPTS+=		require

.include "../../net/libpcap/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../databases/gdbm/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../graphics/gdchart/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
