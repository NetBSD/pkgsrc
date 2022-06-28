# $NetBSD: Makefile,v 1.11 2022/06/28 11:33:22 wiz Exp $

DISTNAME=		Test-Continuous-0.76
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Continuous
COMMENT=		Run your Perl test suite continuously when developing
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-File-ChangeNotify>=0.12:../../devel/p5-File-ChangeNotify
DEPENDS+=		p5-Git-Repository-[0-9]*:../../devel/p5-Git-Repository
DEPENDS+=		p5-Log-Dispatch>=2.22:../../devel/p5-Log-Dispatch
DEPENDS+=		p5-Module-ExtractUse>=0.23:../../devel/p5-Module-ExtractUse
BUILD_DEPENDS+=		p5-YAML>=0.77:../../textproc/p5-YAML

# XXX for test
#BUILD_DEPENDS+=	p5-Test-Class>=0.5:../../devel/p5-Test-Class
#BUILD_DEPENDS+=	p5-Test-Exception>=0.4:../../devel/p5-Test-Exception

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
REPLACE_PERL+=		bin/autoprove
PERL5_PACKLIST=		auto/Test/Continuous/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
