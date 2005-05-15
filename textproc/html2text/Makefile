# $NetBSD: Makefile,v 1.9 2005/05/15 22:02:28 jlam Exp $

DISTNAME=	html2text-1.3.2a
CATEGORIES=	textproc
MASTER_SITES=	http://userpage.fu-berlin.de/~mbayer/tools/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://userpage.fu-berlin.de/~mbayer/tools/html2text.html
COMMENT=	Advanced HTML-to-text converter

USE_LANGUAGES=		c c++
GCC_REQD=		3.0
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		ECHO="${ECHO}"
PKGSRC_USE_TOOLS+=	gunzip

post-build:
	${GUNZIP_CMD} -d ${WRKSRC}/html2text.1.gz ${WRKSRC}/html2textrc.5.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2text ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/html2text.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/html2textrc.5 ${PREFIX}/man/man5/html2textrc.5

.include "../../mk/bsd.pkg.mk"
