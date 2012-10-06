# $NetBSD: Makefile,v 1.18 2012/10/06 14:11:13 asau Exp $

DISTNAME=		pgraf-20010131
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Portable graphics system

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 \
			${PKGMANDIR}/man3 ${PKGMANDIR}/man5 \
			share/doc/pgraf share/examples/pgraf

CONFLICTS=		pgp5-[0-9]*		# Both have a `pgps' executable

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/pgraf.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/doc/pgraf_paper ${DESTDIR}${PREFIX}/share/doc/pgraf
	${INSTALL_DATA} ${WRKSRC}/man/man1/pgraf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/man/man3/pgraf.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_DATA} ${WRKSRC}/man/man5/pgraf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/metagens/*.r ${WRKSRC}/tests/*	\
		${DESTDIR}${PREFIX}/share/examples/pgraf/

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
