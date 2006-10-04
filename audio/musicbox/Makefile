# $NetBSD: Makefile,v 1.26 2006/10/04 20:44:19 wiz Exp $

DISTNAME=	musicbox-1.01p2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
COMMENT=	X11 front-interface for mpg123

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123

USE_LANGUAGES=	c++

WRKSRC=		${WRKDIR}/musicbox-1.01
CFLAGS+=	-D${OPSYS}
MAKE_ENV+=	QT1DIR=${QT1DIR:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musicbox ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/musicbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/musicbox/README

.include "../../x11/qt1/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
