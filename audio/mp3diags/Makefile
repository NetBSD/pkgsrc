# $NetBSD: Makefile,v 1.5 2009/08/26 19:57:11 sno Exp $
#

DISTNAME=	MP3Diags-0.99.05.031
PKGNAME=	${DISTNAME:S/MP3D/mp3d/}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3diags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mp3diags.sourceforge.net/
COMMENT=	mp3 diagnosis tool and tag editor
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

USE_LANGUAGES=	c++

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/MP3Diags ${DESTDIR}${PREFIX}/bin

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
