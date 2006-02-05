# $NetBSD: Makefile,v 1.13 2006/02/05 23:09:37 joerg Exp $

DISTNAME=		pgraf-20010131
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Portable graphics system

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
INSTALLATION_DIRS=	bin include lib man/man1 man/man3 man/man5

CONFLICTS=		pgp5-[0-9]*		# Both have a `pgps' executable

.include "../../mk/x11.buildlink3.mk"

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
