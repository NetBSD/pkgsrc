# $NetBSD: Makefile,v 1.14 2014/02/12 23:17:50 tron Exp $

DISTNAME=	qjson-0.7.1
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qjson/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://qjson.sourceforge.net/
COMMENT=	Qt library for handling JSON data
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

WRKSRC=		${WRKDIR}/qjson

PKGCONFIG_OVERRIDE+=	QJson.pc.in

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	cp ${FILESDIR}/*.* ${WRKSRC}/

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
