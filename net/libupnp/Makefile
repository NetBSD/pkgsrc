# $NetBSD: Makefile,v 1.1.1.1 2006/06/03 23:29:24 rh Exp $
#

DISTNAME=		libupnp-1.3.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pupnp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pupnp.sourceforge.net/
COMMENT=		Portable Universal Plug and Play (UPnP) SDK

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libupnp.pc.in

pre-configure:
.if !exists(/usr/include/malloc.h)
	${LN} -s /usr/include/stdlib.h ${BUILDLINK_DIR}/include/malloc.h
.endif
.if !exists(/usr/include/sys/sysinfo.h)
	${MKDIR} -p ${BUILDLINK_DIR}/include/sys
	${TOUCH} ${BUILDLINK_DIR}/include/sys/sysinfo.h
.endif
.if !exists(/usr/include/linux/if.h)
	${MKDIR} -p ${BUILDLINK_DIR}/include/linux
	${LN} -s /usr/include/net/if.h ${BUILDLINK_DIR}/include/linux/if.h
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
