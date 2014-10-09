# $NetBSD: Makefile,v 1.26 2014/10/09 14:05:59 wiz Exp $

DISTNAME=	hint_unix_serial
PKGNAME=	hint.serial-98.06.12
CATEGORIES=	benchmarks
MASTER_SITES=	http://hint.byu.edu/pub/HINT/source/tar/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hint.byu.edu/
COMMENT=	Scalable benchmark for testing CPU and memory performance

BUILD_TARGET=	DOUBLE INT

WRKSRC=		${WRKDIR}/unix

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
	${CP} ${FILESDIR}/hint.1 ${WRKSRC}/hint.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DOUBLE ${DESTDIR}${PREFIX}/bin/hint-double
	${INSTALL_PROGRAM} ${WRKSRC}/INT ${DESTDIR}${PREFIX}/bin/hint-int
	${INSTALL_MAN} ${WRKSRC}/hint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

benchmark:
	cd ${WRKSRC} ; ${MKDIR} data ; ./DOUBLE | tee hint.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/hint.out /tmp/benches/`domainname`/hint.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
