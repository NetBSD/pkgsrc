# $NetBSD: Makefile,v 1.4 2003/07/17 22:52:14 grant Exp $

DISTNAME=	distfetch-20020930
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Script to fetch only required distribution files

EXTRACT_ONLY=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined

.include "../../mk/bsd.prefs.mk"

do-build:
.for i in distfetch distfetch.1 distfetch.conf
	${SED} "s+__PREFIX__+${PREFIX}+g" < ${FILESDIR}/${i} > ${WRKSRC}/${i}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/distfetch ${PREFIX}/bin/distfetch
	${INSTALL_MAN} ${WRKSRC}/distfetch.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/distfetch
	${INSTALL_DATA} ${WRKSRC}/distfetch.conf \
		${PREFIX}/share/examples/distfetch/distfetch.conf

.include "../../mk/bsd.pkg.mk"

