# $NetBSD: Makefile,v 1.15 2002/12/28 21:24:22 jschauma Exp $
# FreeBSD Id: Makefile,v 1.5 1998/09/26 23:18:07 steve Exp
#

DISTNAME=		xldlas-0.85
PKGREVISION=		2
WRKSRC=			${WRKDIR}/xldlas
CATEGORIES=		math
MASTER_SITES=		http://sunsite.math.klte.hu/mirrors/xldlas/	\
			${MASTER_SITE_SUNSITE:=X11/xapps/math/}
EXTRACT_SUFX=		-source.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://sunsite.math.klte.hu/mirrors/xldlas/
COMMENT=		XForms-based statistics package

ONLY_FOR_PLATFORM=      NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-sparc NetBSD-*-powerpc

USE_BUILDLINK2=		yes
USE_X11BASE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xldlas ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xldlas.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/xldlas
	${CP} -R ${WRKSRC}/help ${PREFIX}/share/xldlas

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xforms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
