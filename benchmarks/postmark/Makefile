# $NetBSD: Makefile,v 1.8 2003/03/29 12:40:13 jmmv Exp $
# FreeBSD ID: ports/benchmarks/postmark/Makefile,v 1.2 1999/09/19 05:13:20 obrien Exp
#

DISTNAME=       postmark-1_5.c
PKGNAME=	postmark-1.5
WRKSRC=		${WRKDIR}
CATEGORIES=	benchmarks
MASTER_SITES=   http://www.netapp.com/ftp/
EXTRACT_SUFX=	#

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.netapp.com/tech_library/3022.html
COMMENT=	NetApps file system benchmark

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} postmark.c

NO_CONFIGURE=	yes

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o postmark postmark.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/postmark ${PREFIX}/sbin

benchmark:
	@(cd ${WRKSRC}; (${ECHO} "set number 5000" ;\
	 ${ECHO} "set size 100 50000" ;\
	 ${ECHO} "run") | ./postmark | tee postmark.out)

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/postmark.out /tmp/benches/`domainname`/postmark.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
