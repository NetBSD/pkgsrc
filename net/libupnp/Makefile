# $NetBSD: Makefile,v 1.4 2007/06/07 08:08:16 rh Exp $
#

DISTNAME=		libupnp-1.4.6
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pupnp/}
EXTRACT_SUFX=		.tar.bz2

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

post-install:
.for doc in IXML_Programming_Guide UPnP_Programming_Guide
	${INSTALL_DATA} ${WRKSRC}/docs/dist/${doc}.pdf			\
			${PREFIX}/share/doc/${PKGNAME_NOREV}
.endfor
.for dir in ixml upnp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME_NOREV}/html/${dir}
	${INSTALL_DATA} ${WRKSRC}/docs/dist/${doc}/html/${dir}/*	\
			${PREFIX}/share/doc/${PKGNAME_NOREV}/html/${dir}
.endfor

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
