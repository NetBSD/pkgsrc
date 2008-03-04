# $NetBSD: Makefile,v 1.31 2008/03/04 18:12:59 jlam Exp $

DISTNAME=		xldlas-0.85
PKGREVISION=		5
CATEGORIES=		math
MASTER_SITES=		http://sunsite.math.klte.hu/mirrors/xldlas/	\
			${MASTER_SITE_SUNSITE:=X11/xapps/math/}
EXTRACT_SUFX=		-source.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sunsite.math.klte.hu/mirrors/xldlas/
COMMENT=		XForms-based statistics package

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/xldlas
USE_X11BASE=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xldlas ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xldlas.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xldlas
	${CP} -R ${WRKSRC}/help ${DESTDIR}${PREFIX}/share/xldlas

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
