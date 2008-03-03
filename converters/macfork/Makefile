# $NetBSD: Makefile,v 1.18 2008/03/03 05:51:08 jlam Exp $

DISTNAME=	macfork-1.0
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.cs.cmu.edu/~ajw/public/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.cmu.edu/afs/cs/user/ajw/www/software/
COMMENT=	Tool for extracting data from Macintosh resource forks

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/macfork
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

DOCDIR=		${PREFIX}/share/doc/macfork

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/macfork ${DESTDIR}${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC:Q}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
