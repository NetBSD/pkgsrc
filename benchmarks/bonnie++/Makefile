# $NetBSD: Makefile,v 1.10 2004/05/05 00:38:07 danw Exp $
#

DISTNAME=       bonnie++-1.03a
CATEGORIES=	benchmarks
MASTER_SITES=   http://www.coker.com.au/bonnie++/
EXTRACT_SUFX=	.tgz

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.coker.com.au/bonnie++/
COMMENT=	Enhanced performance Test of Filesystem I/O

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS=		make
USE_GCC_SHLIB=		YES
REPLACE_PERL=		bon_csv2txt.in bon_csv2html.in

INSTALLATION_DIRS=	bin man/man1 man/man8 sbin

benchmark:
	@cd ${WRKSRC}; ./bonnie++ -u ${ROOT_USER}:${ROOT_GROUP} | tee bonnie.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/bonnie.out /tmp/benches/`domainname`/bonnie++.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
