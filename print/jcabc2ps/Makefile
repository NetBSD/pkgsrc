# $NetBSD: Makefile,v 1.7 2012/10/08 13:45:40 asau Exp $
#

DISTNAME=	jcabc2ps-src
PKGNAME=	jcabc2ps-20060106
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://ecf-guest.mit.edu/~jc/music/abc/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ecf-guest.mit.edu/~jc/music/abc/src/
COMMENT=	Music typesetting program for abc

WRKSRC=		${WRKDIR}/jcabc2ps

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		getline
SUBST_STAGE.getline=	pre-configure
SUBST_MESSAGE.getline=	Fixing conflict with POSIX getline.
SUBST_FILES.getline=	jcabc2ps.c format.c music.c util.c util.h save/music.c
SUBST_SED.getline=	-e 's/getline/mygetline/'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jcabc2ps ${DESTDIR}${PREFIX}/bin/.

.include "../../mk/bsd.pkg.mk"
