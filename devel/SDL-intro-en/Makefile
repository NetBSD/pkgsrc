# $NetBSD: Makefile,v 1.1.1.1 2005/06/25 03:04:26 minskim Exp $
#

DISTNAME=	SDL-1.0-english-intro
PKGNAME=	SDL-intro-en-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/archives/

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://www.libsdl.org/docs.php
COMMENT=	Simple DirectMedia Layer introduction (English)

WRKSRC=		${WRKDIR}/intro.en
DEST=		${PREFIX}/share/doc/SDL-intro/en

NO_CONFIGURE=	YES
NO_BUILD=	YES

# Remove links
post-patch:
	${RM} ${WRKSRC}/index.html

do-install:
	${INSTALL_DATA_DIR} ${DEST}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DEST}
	${LN} -s ${DEST}/toc.html ${DEST}/index.html

.include "../../mk/bsd.pkg.mk"
