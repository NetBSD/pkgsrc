# $NetBSD: Makefile,v 1.8 2000/03/16 12:16:52 wiz Exp $

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
	-@${CP} ${WRKSRC}/iozone.out /tmp/benches/`domainname`/iozone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
