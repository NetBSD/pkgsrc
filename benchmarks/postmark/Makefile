# $NetBSD: Makefile,v 1.1.1.2 1999/12/06 18:59:40 rh Exp $
# FreeBSD ID: ports/benchmarks/postmark/Makefile,v 1.2 1999/09/19 05:13:20 obrien Exp
#

DISTNAME=       postmark-1_11.c
PKGNAME=	postmark-1.11
CATEGORIES=	benchmarks
MASTER_SITES=   http://www.netapp.com/ftp/		\
		http://www.taronga.com/~nick/files/
EXTRACT_SUFX=	#

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.netapp.com/tech_library/3022.html

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} postmark.c

NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o postmark postmark.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/postmark ${PREFIX}/sbin

benchmark:
	@(cd ${WRKSRC}; ${ECHO} run | ./postmark | tee postmark.out)

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/postmark.out /tmp/benches/`domainname`/postmark.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
