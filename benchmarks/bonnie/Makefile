# $NetBSD: Makefile,v 1.15 2000/03/16 12:16:50 wiz Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/26 23:09:14 jseger Exp
#

DISTNAME=       Bonnie
PKGNAME=	bonnie-1.0
CATEGORIES=	benchmarks
MASTER_SITES=   ftp://ftp0.sunet.se/pub/benchmark/Bonnie/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.textuality.com/bonnie/index.html

NO_CONFIGURE=	yes

MANCOMPRESSED_IF_MANZ=	yes

post-extract:
	${MV} ${WRKSRC}/Bonnie.c ${WRKSRC}/bonnie.c

benchmark:
	@(cd ${WRKSRC}; ./bonnie | tee bonnie.out)

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/bonnie.out /tmp/benches/`domainname`/bonnie.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
