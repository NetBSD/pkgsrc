# $NetBSD: Makefile,v 1.17 2006/01/20 16:15:52 jmmv Exp $

DISTNAME=	id3v2-0.1.11
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3v2/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://id3v2.sourceforge.net/
COMMENT=	Command line editor for id3v2 tags

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/id3v2 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/id3v2.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/id3v2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/id3v2/README

.include "../../audio/id3lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
