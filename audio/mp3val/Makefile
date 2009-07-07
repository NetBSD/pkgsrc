# $NetBSD: Makefile,v 1.1.1.1 2009/07/07 19:36:19 drochner Exp $
#

DISTNAME=	mp3val-0.1.8-src
PKGNAME=	mp3val-0.1.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3val/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mp3val.sourceforge.net/
COMMENT=	mp3 checker
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.linux
BUILD_TARGET=	mp3val
PKG_DESTDIR_SUPPORT= user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3val ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
