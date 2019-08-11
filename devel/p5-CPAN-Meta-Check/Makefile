# $NetBSD: Makefile,v 1.22 2019/08/11 13:18:55 wiz Exp $

DISTNAME=	CPAN-Meta-Check-0.014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-Meta-Check
COMMENT=	Perl module to verify requirements in a CPAN::Meta object
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.16.0,p5-CPAN-Meta>=2.132830}:../../devel/p5-CPAN-Meta
#DEPENDS+=	{perl>=5.18.0,p5-CPAN-Meta-Requirements>=2.122}:../../devel/p5-CPAN-Meta-Requirements

# use BUILD_DEPENDS+= as 'make test' dependency
# perl 5.20.0 has 1.000019, but test wants following version
BUILD_DEPENDS+=	p5-Module-Metadata>=1.00023:../../devel/p5-Module-Metadata

BUILD_DEPENDS+= p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PERL5_PACKLIST=		auto/CPAN/Meta/Check/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
