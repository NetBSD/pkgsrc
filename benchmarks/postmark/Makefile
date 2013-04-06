# $NetBSD: Makefile,v 1.17 2013/04/06 12:03:59 rodent Exp $

DISTNAME=	postmark-1_5.c
PKGNAME=	postmark-1.5
CATEGORIES=	benchmarks
MASTER_SITES=	http://fsbench.filesystems.org/bench/
EXTRACT_SUFX=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netapp.com/tech_library/3022.html
COMMENT=	NetApps file system benchmark

EXTRACT_CMD=	${CP} $$extract_file postmark.c

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	sbin

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o postmark postmark.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/postmark ${DESTDIR}${PREFIX}/sbin

benchmark:
	@(cd ${WRKSRC}; (${ECHO} "set number 5000" ;\
	 ${ECHO} "set size 100 50000" ;\
	 ${ECHO} "run") | ./postmark | tee postmark.out)

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/postmark.out /tmp/benches/`domainname`/postmark.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
