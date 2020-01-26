# $NetBSD: Makefile,v 1.6 2020/01/26 05:26:12 rillig Exp $
#

DISTNAME=	mp3val-0.1.8-src
PKGNAME=	mp3val-0.1.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3val/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mp3val.sourceforge.net/
COMMENT=	Checker for mp3
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.linux
BUILD_TARGET=	mp3val

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3val ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
