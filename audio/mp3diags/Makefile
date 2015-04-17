# $NetBSD: Makefile,v 1.46 2015/04/17 15:52:58 adam Exp $

DISTNAME=	MP3Diags-1.2.01
PKGNAME=	${DISTNAME:S/MP3D/mp3d/}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3diags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mp3diags.sourceforge.net/
COMMENT=	MP3 diagnosis tool and tag editor
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin

USE_LANGUAGES=	c++

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/MP3Diags ${DESTDIR}${PREFIX}/bin

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
