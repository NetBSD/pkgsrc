# $NetBSD: Makefile,v 1.18 2001/07/16 22:50:47 garbled Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/26 23:09:14 jseger Exp
#

DISTNAME=       bonnie
PKGNAME=	bonnie-2.06
CATEGORIES=	benchmarks
MASTER_SITES=   http://www.textuality.com/bonnie/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.textuality.com/bonnie/index.html
COMMENT=	Performance Test of Filesystem I/O

NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}
MANCOMPRESSED_IF_MANZ=	yes

post-extract:
	${MV} ${WRKSRC}/Bonnie.c ${WRKSRC}/bonnie.c

benchmark:
	@(cd ${WRKSRC}; ./bonnie | tee bonnie.out)

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/bonnie.out /tmp/benches/`domainname`/bonnie.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
