# $NetBSD: Makefile,v 1.16 2006/02/05 23:08:19 joerg Exp $
#

DISTNAME=       bonnie++-1.03a
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=   http://www.coker.com.au/bonnie++/
EXTRACT_SUFX=	.tgz

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.coker.com.au/bonnie++/
COMMENT=	Enhanced performance Test of Filesystem I/O

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl:run
REPLACE_PERL=		bon_csv2txt.in bon_csv2html.in

INSTALLATION_DIRS=	bin man/man1 man/man8 sbin

benchmark:
	@cd ${WRKSRC}; ./bonnie++ -u ${ROOT_USER}:${ROOT_GROUP} | tee bonnie.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/bonnie.out /tmp/benches/`domainname`/bonnie++.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
