# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:29 jlam Exp $

DISTNAME=	distfetch-20020930
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Script to fetch only required distribution files

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin man/man1

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

