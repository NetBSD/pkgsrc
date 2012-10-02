# $NetBSD: Makefile,v 1.10 2012/10/02 17:10:57 tron Exp $
#

DISTNAME=	qgoogletranslator-1.2.1
PKGREVISION=	8
CATEGORIES=	editors
MASTER_SITES=	http://qgt.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/qgt/
COMMENT=	Qt gui for google translate based on ajax api
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123

USE_LANGUAGES=	c++ c
USE_CMAKE=	yes

LDFLAGS.DragonFly=	-lX11

FIND_PREFIX:=	MPG123DIR=mpg123
.include "../../mk/find-prefix.mk"

SUBST_CLASSES+=		mpg123-cmd
SUBST_STAGE.mpg123-cmd=	pre-configure
SUBST_FILES.mpg123-cmd=	src/defines.h.in
SUBST_SED.mpg123-cmd=	-e 's,/usr/bin/mpg123,${MPG123DIR}/bin/mpg123,'
SUBST_SED.mpg123-cmd+=	-e 's,/usr/local/bin/mpg123,${MPG123DIR}/bin/mpg123,'

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
