# $NetBSD: Makefile,v 1.5 2007/06/19 01:40:13 rh Exp $
#

DISTNAME=		libupnp-1.6.0-rc1
PKGNAME=		${DISTNAME:S/-rc1/rc1/}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pupnp/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pupnp.sourceforge.net/
COMMENT=		Portable Universal Plug and Play (UPnP) SDK

WRKSRC=			${WRKDIR}/${DISTNAME:S/-rc1//}
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libupnp.pc.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME_NOREV}
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
