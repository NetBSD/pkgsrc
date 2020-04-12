# $NetBSD: Makefile,v 1.68 2020/04/12 08:28:19 adam Exp $

DISTNAME=	MP3Diags-unstable-1.5.01
PKGNAME=	${DISTNAME:S/MP3D/mp3d/:C/-unsable//}
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3diags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mp3diags.sourceforge.net/
COMMENT=	MP3 diagnosis tool and tag editor
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin

USE_LANGUAGES=	c++

do-configure:
	${RUN} cd ${WRKSRC} && ${QTDIR}/bin/qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/MP3Diags-unstable \
		${DESTDIR}${PREFIX}/bin/MP3Diags

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
