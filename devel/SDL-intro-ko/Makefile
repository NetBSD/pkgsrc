# $NetBSD: Makefile,v 1.3 2012/10/31 11:16:32 asau Exp $
#

DISTNAME=	SDL-1.0-korean-intro
PKGNAME=	SDL-intro-ko-1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/archives/

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://www.libsdl.org/docs.php
COMMENT=	Simple DirectMedia Layer introduction (Korean)

WRKSRC=		${WRKDIR}/intro.ko
DEST=		${PREFIX}/share/doc/SDL-intro.ko

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
