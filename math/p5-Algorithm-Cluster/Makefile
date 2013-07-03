# $NetBSD: Makefile,v 1.1 2013/07/03 14:26:03 sno Exp $
#

DISTNAME=	Algorithm-Cluster-1.50
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Cluster/
COMMENT=	Perl interface to the C Clustering Library
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Algorithm/Cluster/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
