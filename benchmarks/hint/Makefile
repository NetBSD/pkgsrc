# $NetBSD: Makefile,v 1.5 1999/02/10 14:59:50 frueauf Exp $
# FreeBSD: Makefile,v 1.1.1.1 1998/06/15 18:09:43 ghelmer Exp
#

DISTNAME=	hint_unix_serial
PKGNAME=	hint.serial-98.06.12
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.scl.ameslab.gov/pub/HINT/source/tar/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.scl.ameslab.gov/Projects/HINT/

EXTRACT_BEFORE_ARGS=-xf
WRKSRC=		${WRKDIR}/unix
ALL_TARGET=	DOUBLE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DOUBLE ${PREFIX}/bin/hint
	${INSTALL_MAN} ${WRKSRC}/hint.1 ${PREFIX}/man/man1

benchmark:
	cd ${WRKSRC} ; mkdir -p data ; ./DOUBLE | tee hint.out

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@cp ${WRKSRC}/hint.out /tmp/benches/`domainname`/hint.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
