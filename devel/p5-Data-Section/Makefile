# $NetBSD: Makefile,v 1.3 2010/02/15 14:55:36 sno Exp $
#

DISTNAME=	Data-Section-0.100270
PKGNAME=	p5-${DISTNAME:S/100270/100.270/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Section/
COMMENT=	Perl 5 module to read multiple hunks of data out of your DATA section
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MRO-Compat>=0.09:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Sub-Exporter>=0.979:../../devel/p5-Sub-Exporter

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Data/Section/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
