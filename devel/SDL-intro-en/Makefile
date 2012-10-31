# $NetBSD: Makefile,v 1.4 2012/10/31 11:16:32 asau Exp $
#

DISTNAME=	SDL-1.0-english-intro
PKGNAME=	SDL-intro-en-1.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/archives/

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://www.libsdl.org/docs.php
COMMENT=	Simple DirectMedia Layer introduction (English)

WRKSRC=		${WRKDIR}/intro.en
DEST=		${PREFIX}/share/doc/SDL-intro.en

NO_CONFIGURE=	YES
NO_BUILD=	YES

# Remove links
post-patch:
	${RM} ${WRKSRC}/index.html

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DEST}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DESTDIR}${DEST}
	${LN} -s toc.html ${DESTDIR}${DEST}/index.html

.include "../../mk/bsd.pkg.mk"
