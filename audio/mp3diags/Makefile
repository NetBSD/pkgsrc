# $NetBSD: Makefile,v 1.1.1.1 2009/07/07 09:34:39 drochner Exp $
#

DISTNAME=	MP3Diags-0.99.02.020
PKGNAME=	mp3diags-0.99.02.020
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3diags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mp3diags.sourceforge.net/
COMMENT=	mp3 diagnosis tool and tag editor
LICENSE=	gnu-gpl-v2
PKG_DESTDIR_SUPPORT= user-destdir

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
