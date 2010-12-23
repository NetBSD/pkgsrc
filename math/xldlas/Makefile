# $NetBSD: Makefile,v 1.35 2010/12/23 11:44:49 dsainty Exp $

DISTNAME=		xldlas-0.85
PKGREVISION=		7
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SUNSITE:=science/visualization/}
EXTRACT_SUFX=		-source.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		# http://sunsite.math.klte.hu/mirrors/xldlas/
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

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
