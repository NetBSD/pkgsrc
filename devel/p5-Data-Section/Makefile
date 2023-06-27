# $NetBSD: Makefile,v 1.29 2023/06/27 02:36:25 wen Exp $

DISTNAME=	Data-Section-0.200008
PKGNAME=	p5-Data-Section-0.200.008
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Section
COMMENT=	Perl 5 module to read multiple hunks of data out of your DATA section
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-MRO-Compat>=0.09:../../devel/p5-MRO-Compat
DEPENDS+=		p5-Sub-Exporter>=0.979:../../devel/p5-Sub-Exporter
#TOOL_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
TOOL_DEPENDS+=		p5-Test-FailWarnings-[0-9]*:../../devel/p5-Test-FailWarnings

PERL5_PACKLIST=		auto/Data/Section/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
