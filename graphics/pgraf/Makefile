# $NetBSD: Makefile,v 1.5 2001/04/28 23:59:19 jtb Exp $

DISTNAME=		pgraf-20010131
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
COMMENT=		Portable graphics system

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_X11=		YES

CONFLICTS=		pgp5-*		# Both have a `pgps' executable

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/pgraf.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pgraf
	${INSTALL_DATA} ${WRKSRC}/doc/pgraf_paper ${PREFIX}/share/doc/pgraf
	${INSTALL_DATA} ${WRKSRC}/man/man1/pgraf.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/man/man3/pgraf.3 ${PREFIX}/man/man3
	${INSTALL_DATA} ${WRKSRC}/man/man5/pgraf.5 ${PREFIX}/man/man5
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pgraf
	${INSTALL_DATA} ${WRKSRC}/metagens/*.r ${WRKSRC}/tests/*	\
		${PREFIX}/share/examples/pgraf/

.include "../../mk/bsd.pkg.mk"
