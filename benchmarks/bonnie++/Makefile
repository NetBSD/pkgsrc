# $NetBSD: Makefile,v 1.6 2002/09/20 23:48:12 jlam Exp $
#

DISTNAME=       bonnie++-1.02c
CATEGORIES=	benchmarks
MASTER_SITES=   http://www.coker.com.au/bonnie++/
EXTRACT_SUFX=	.tgz

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.coker.com.au/bonnie++/
COMMENT=	Enhanced performance Test of Filesystem I/O

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
REPLACE_PERL=		bon_csv2txt.in bon_csv2html.in

benchmark:
	@cd ${WRKSRC}; ./bonnie++ -u ${ROOT_USER}:${ROOT_GROUP} | tee bonnie.out

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/bonnie.out /tmp/benches/`domainname`/bonnie++.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
