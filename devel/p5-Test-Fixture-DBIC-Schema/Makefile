# $NetBSD: Makefile,v 1.14 2017/06/05 14:23:43 ryoon Exp $
#

DISTNAME=	Test-Fixture-DBIC-Schema-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Fixture-DBIC-Schema/
COMMENT=	Perl 5 module providing a DBIx::Class::Schema fixture data loader
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Fixture/DBIC/Schema/.packlist

DEPENDS+=	p5-DBIx-Class>=0.08008:../../databases/p5-DBIx-Class
#DEPENDS+=	{perl>=5.7.3,p5-Filter-[0-9]*}:../../textproc/p5-Filter
DEPENDS+=	p5-Kwalify>=1.16:../../textproc/p5-Kwalify
DEPENDS+=	p5-Params-Validate>=0.89:../../devel/p5-Params-Validate
DEPENDS+=	p5-YAML-Syck>=1.00:../../textproc/p5-YAML-Syck
# For test really
BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
