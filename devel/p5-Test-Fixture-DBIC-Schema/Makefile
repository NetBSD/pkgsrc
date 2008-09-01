# $NetBSD: Makefile,v 1.1.1.1 2008/09/01 21:45:58 seb Exp $
#

DISTNAME=	Test-Fixture-DBIC-Schema-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Fixture-DBIC-Schema/
COMMENT=	Perl 5 module providing a DBIx::Class::Schema fixture data loader

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Fixture/DBIC/Schema/.packlist

DEPENDS+=	p5-DBIx-Class>=0.08008:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Kwalify>=1.16:../../textproc/p5-Kwalify
DEPENDS+=	p5-Params-Validate>=0.89:../../devel/p5-Params-Validate
DEPENDS+=	p5-YAML-Syck>=1.00:../../textproc/p5-YAML-Syck
# For test really
BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
