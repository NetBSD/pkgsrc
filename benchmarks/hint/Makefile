# $NetBSD: Makefile,v 1.18 2004/12/03 15:14:51 wiz Exp $
# FreeBSD: Makefile,v 1.1.1.1 1998/06/15 18:09:43 ghelmer Exp
#

DISTNAME=	hint_unix_serial
PKGNAME=	hint.serial-98.06.12
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.scl.ameslab.gov/pub/HINT/source/tar/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.scl.ameslab.gov/Projects/HINT/
COMMENT=	Scalable benchmark for testing CPU and memory performance

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=	DOUBLE INT

WRKSRC=		${WRKDIR}/unix

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DOUBLE ${PREFIX}/bin/hint-double
	${INSTALL_PROGRAM} ${WRKSRC}/INT ${PREFIX}/bin/hint-int
	${INSTALL_MAN} ${WRKSRC}/hint.1 ${PREFIX}/man/man1

benchmark:
	cd ${WRKSRC} ; ${MKDIR} data ; ./DOUBLE | tee hint.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/hint.out /tmp/benches/`domainname`/hint.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
