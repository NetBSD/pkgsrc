# $NetBSD: Makefile,v 1.7 1999/06/21 09:57:03 agc Exp $

DISTNAME=		iozone
PKGNAME=		iozone-1.14b
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.bme.hu/pub/OS/Linux/tsx-11/sources/test_suites/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes

do-build:
	(cd ${WRKDIR} &&					\
	case `uname -s` in					\
	SunOS)							\
		${CC} -O2 -DSYSTYPE_SYSV -o iozone iozone.c ;;	\
	NetBSD)							\
		${CC} -O2 -o iozone iozone.c ;;			\
	esac)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin

benchmark:
	@(cd ${WRKSRC}; ./iozone 100 | tee iozone.out)

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@cp ${WRKSRC}/iozone.out /tmp/benches/`domainname`/iozone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
