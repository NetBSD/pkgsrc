# $NetBSD: Makefile,v 1.21 2004/04/24 04:28:20 snj Exp $
# FreeBSD Id: Makefile,v 1.5 1998/09/26 23:18:07 steve Exp
#

DISTNAME=		xldlas-0.85
PKGREVISION=		3
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
USE_BUILDLINK3=		yes
USE_X11BASE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xldlas ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xldlas.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/xldlas
	${CP} -R ${WRKSRC}/help ${PREFIX}/share/xldlas

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
