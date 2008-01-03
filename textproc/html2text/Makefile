# $NetBSD: Makefile,v 1.14 2008/01/03 14:05:38 obache Exp $

DISTNAME=	html2text-1.3.2a
CATEGORIES=	textproc
MASTER_SITES=	http://www.mbayer.de/html2text/downloads/	\
		${MASTER_SITE_SUNSITE:=apps/www/converters/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.mbayer.de/html2text/
COMMENT=	Advanced HTML-to-text converter

USE_LANGUAGES=		c c++
GCC_REQD+=		3.0
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		ECHO=${ECHO:Q}
USE_TOOLS+=		gunzip
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

post-build:
	${GUNZIP_CMD} -d ${WRKSRC}/html2text.1.gz ${WRKSRC}/html2textrc.5.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2text ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/html2text.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/html2textrc.5 ${PREFIX}/${PKGMANDIR}/man5/html2textrc.5

.include "../../mk/bsd.pkg.mk"
