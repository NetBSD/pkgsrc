# $NetBSD: Makefile,v 1.20 2023/12/16 10:01:30 mef Exp $

DISTNAME=	Config-MVP-Reader-INI-2.101465
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Config-MVP-Reader-INI
COMMENT=	Perl5 module providing an MVP config reader for .ini files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Config-INI-[0-9]*:../../devel/p5-Config-INI
DEPENDS+=	p5-Config-MVP>=2.0:../../devel/p5-Config-MVP
DEPENDS+=	p5-Moose>=0.91:../../devel/p5-Moose
# for make test
TEST_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Config/MVP/Reader/INI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
