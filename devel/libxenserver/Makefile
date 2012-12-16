# $NetBSD: Makefile,v 1.5 2012/12/16 01:52:11 obache Exp $
#

DISTNAME=	libxenserver-5.6.100-1-src
PKGNAME=	${DISTNAME:S/-1-src//}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://community.citrix.com/download/attachments/38633496/

MAINTAINER=	sborrill@NetBSD.org
HOMEPAGE=	http://community.citrix.com/cdn/xs/sdks/
COMMENT=	Citrix XenServer SDK for C
LICENSE=	gnu-gpl-v2

EXTRACT_SUFX=	.tar.bz2
WRKSRC=		${WRKDIR}/libxenserver
MAJOR=		1
MINOR=		3
BUILD_TARGET=	libxenserver.so
USE_TOOLS+=	gmake pax

PLIST_SUBST+=	MAJOR=${MAJOR:Q} MINOR=${MINOR:Q}

INSTALLATION_DIRS=	include/xen/api
INSTALLATION_DIRS+=	share/examples/libxenserver lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/libxenserver.so.${MAJOR}.${MINOR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libxenserver.so ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC}/include/xen/api && pax -rw *.h ${DESTDIR}${PREFIX}/include/xen/api
.for example in test_event_handling.c test_failures.c test_vm_ops.c
	${INSTALL_DATA} ${WRKSRC}/test/${example} \
	    ${DESTDIR}${PREFIX}/share/examples/libxenserver
.endfor

.include "../../mk/bsd.prefs.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
