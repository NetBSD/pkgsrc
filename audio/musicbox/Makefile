# $NetBSD: Makefile,v 1.27 2008/03/02 06:10:33 jlam Exp $

DISTNAME=	musicbox-1.01p2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
COMMENT=	X11 front-interface for mpg123

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

WRKSRC=		${WRKDIR}/musicbox-1.01
CFLAGS+=	-D${OPSYS}
MAKE_ENV+=	QT1DIR=${QT1DIR:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musicbox ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/musicbox
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/musicbox/README

.include "../../x11/qt1/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
