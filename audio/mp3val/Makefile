# $NetBSD: Makefile,v 1.7 2025/11/17 11:00:21 wiz Exp $
#

DISTNAME=	mp3val-0.1.8-src
PKGNAME=	mp3val-0.1.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3val/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mp3val.sourceforge.net/
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
