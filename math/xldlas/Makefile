# $NetBSD: Makefile,v 1.25 2005/06/17 03:50:20 jlam Exp $

DISTNAME=		xldlas-0.85
PKGREVISION=		4
CATEGORIES=		math
MASTER_SITES=		http://sunsite.math.klte.hu/mirrors/xldlas/	\
			${MASTER_SITE_SUNSITE:=X11/xapps/math/}
EXTRACT_SUFX=		-source.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sunsite.math.klte.hu/mirrors/xldlas/
COMMENT=		XForms-based statistics package

ONLY_FOR_PLATFORM=      NetBSD-*-alpha NetBSD-*-arm NetBSD-*-arm32	\
			NetBSD-*-i386 NetBSD-*-m68k NetBSD-*-mipsel	\
			NetBSD-*-ns32k NetBSD-*-sparc NetBSD-*-powerpc

WRKSRC=			${WRKDIR}/xldlas
USE_X11BASE=		yes
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xldlas ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xldlas.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/xldlas
	${CP} -R ${WRKSRC}/help ${PREFIX}/share/xldlas

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
