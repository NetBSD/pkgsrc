# $NetBSD: Makefile,v 1.10 2002/11/21 10:23:06 grant Exp $

DISTNAME=		ntop-2.1
PKGNAME=		ntop2-2.1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ntop/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ntop.org/
COMMENT=		shows network usage (similar to "top" for processes)

CONFLICTS=		ntop-[0-9]*

WRKSRC=                 ${WRKDIR}/ntop

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=          yes
USE_GNU_READLINE=	yes
# --enable-micro-ntop causes compile to fail 
CONFIGURE_ARGS+=	--disable-mysql
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PTHREAD_OPTS+=		require

.include "../../net/libpcap/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../graphics/gdchart/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
