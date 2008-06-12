# $NetBSD: Makefile,v 1.16 2008/06/12 02:14:32 joerg Exp $

DISTNAME=	Plotmtv1.4.1
PKGNAME=	plotmtv-1.4.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multipurpose X11 plotting program

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_IMAKE=	yes

INSTALLATION_DIRS=	share/examples/plotmtv

post-extract:
	@${MV} -f ${WRKSRC}/Docs/plotmtv.man ${WRKSRC}/Plot

post-install:
	${INSTALL_DATA} ${WRKSRC}/Tests/*.mtv ${DESTDIR}${PREFIX}/share/examples/plotmtv
	${INSTALL_SCRIPT} ${WRKSRC}/Tests/run.sh ${WRKSRC}/Tests/run.csh \
		${DESTDIR}${PREFIX}/share/examples/plotmtv

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
