# $NetBSD: Makefile,v 1.15 2009/07/07 22:01:50 joerg Exp $

DISTNAME=	html2text-1.3.2a
CATEGORIES=	textproc
MASTER_SITES=	http://www.mbayer.de/html2text/downloads/	\
		${MASTER_SITE_SUNSITE:=apps/www/converters/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.mbayer.de/html2text/
COMMENT=	Advanced HTML-to-text converter

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
GCC_REQD+=		3.0
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		ECHO=${ECHO:Q}
USE_TOOLS+=		gunzip
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

post-build:
	${GUNZIP_CMD} -d ${WRKSRC}/html2text.1.gz ${WRKSRC}/html2textrc.5.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2text ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/html2text.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/html2textrc.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/html2textrc.5

.include "../../mk/bsd.pkg.mk"
