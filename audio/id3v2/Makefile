# $NetBSD: Makefile,v 1.11 2004/10/03 00:13:06 tv Exp $

DISTNAME=	id3v2-0.1.10
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3v2/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://id3v2.sourceforge.net/
COMMENT=	Command line editor for id3v2 tags

USE_LANGUAGES=	c c++
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/id3v2 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/id3v2.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/id3v2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/id3v2/README

.include "../../audio/id3lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
