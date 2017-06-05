# $NetBSD: Makefile,v 1.12 2017/06/05 14:22:30 ryoon Exp $
#

DISTNAME=		Net-Cassandra-0.35
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-Cassandra/
COMMENT=		Perl5 module for accessing the Cassandra database

DEPENDS+=		p5-Bit-Vector>=0:../../devel/p5-Bit-Vector
DEPENDS+=		p5-Moose>=0.56:../../devel/p5-Moose
DEPENDS+=		p5-MooseX-StrictConstructor>=0:../../devel/p5-MooseX-StrictConstructor

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/Cassandra/.packlist

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
