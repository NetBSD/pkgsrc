# $NetBSD: Makefile,v 1.13 2002/04/17 04:45:15 fredb Exp $
# FreeBSD Id: Makefile,v 1.5 1998/09/26 23:18:07 steve Exp
#

DISTNAME=		xldlas-0.85
PKGREVISION=		1
WRKSRC=			${WRKDIR}/xldlas
CATEGORIES=		math
MASTER_SITES=		http://sunsite.math.klte.hu/mirrors/xldlas/	\
			${MASTER_SITE_SUNSITE:=X11/xapps/math/}
EXTRACT_SUFX=		-source.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://sunsite.math.klte.hu/mirrors/xldlas/
COMMENT=		XForms-based statistics package

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		xforms>=0.9999:../../x11/xforms

ONLY_FOR_PLATFORM=      NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-sparc NetBSD-*-powerpc

USE_X11BASE=		yes
USE_XPM=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xldlas ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xldlas.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/xldlas
	${CP} -R ${WRKSRC}/help ${PREFIX}/share/xldlas

.include "../../mk/bsd.pkg.mk"
