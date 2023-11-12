# $NetBSD: Makefile,v 1.23 2023/11/12 13:21:27 wiz Exp $

DISTNAME=	xmbdfed-4.7
PKGREVISION=	1
CATEGORIES=	fonts graphics x11
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/vins/dists/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20090227090450/http://crl.nmsu.edu/~mleisher/xmbdfed.html
COMMENT=	Motif-based BDF font editor with lots of features
LICENSE=	mit AND public-domain

USE_TOOLS+=	gzip

MAKE_ENV+=	GZIP=${GUNZIP_CMD:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/${PKGBASE}
INSTALLATION_DIRS+=	share/pixmaps share/applications

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbdfed		\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmbdfed.man		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xmbdfed.1
	${INSTALL_DATA} ${WRKSRC}/xmbdfedrc		\
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA} ${FILESDIR}/xmbdfed.desktop	\
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/xmbdfed.png		\
		${DESTDIR}${PREFIX}/share/pixmaps

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
