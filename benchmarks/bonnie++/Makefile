# $NetBSD: Makefile,v 1.4 2001/11/28 05:20:38 jlam Exp $
#

DISTNAME=       bonnie++-1.01
CATEGORIES=	benchmarks
MASTER_SITES=   http://www.coker.com.au/bonnie++/
EXTRACT_SUFX=	.tgz

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.coker.com.au/bonnie++/
COMMENT=	Enhanced performance Test of Filesystem I/O

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
REPLACE_PERL=		bon_csv2txt.in bon_csv2html.in

benchmark:
	@(cd ${WRKSRC}; ./bonnie++ -u 0:0 | tee bonnie.out)

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/bonnie.out /tmp/benches/`domainname`/bonnie++.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
