# $NetBSD: Makefile,v 1.1 2002/07/23 06:52:38 cjs Exp $

DISTNAME=		ntop-2.0.99-rc2
PKGNAME=		ntop2-2.0.99rc2
#PKGREVISION=		0
CATEGORIES=		net
CONFLICTS=		ntop-*
MASTER_SITES=		http://luca.ntop.org/
EXTRACT_SUFX=		.tgz
WRKSRC=                 ${WRKDIR}/RC2/ntop

HOMEPAGE=		http://www.ntop.org/
COMMENT=		shows network usage (similar to "top" for processes)

USE_GMAKE=		YES
USE_GNU_READLINE=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK_ONLY=     YES

GNU_CONFIGURE=          YES
CONFIGURE_ARGS+=	--disable-mysql --disable-mt
## --enable-micro-ntop causes compile to fail 
#CONFIGURE_ARGS+=        --disable-mysql --disable-mt

DEPENDS+=		gdchart:../../graphics/gdchart

.include "../../net/libpcap/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../databases/gdbm/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
