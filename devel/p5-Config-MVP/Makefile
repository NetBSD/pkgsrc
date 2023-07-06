# $NetBSD: Makefile,v 1.27 2023/07/06 09:38:51 wiz Exp $

DISTNAME=	Config-MVP-2.200012
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Config-MVP
COMMENT=	Perl5 module for multivalue-property package-oriented configuration
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Load>=0.17:../../devel/p5-Class-Load
DEPENDS+=	p5-Moose>=0.91:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-OneArgNew-[0-9]*:../../devel/p5-MooseX-OneArgNew
DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-Role-HasMessage-[0-9]*:../../devel/p5-Role-HasMessage
DEPENDS+=	p5-Role-Identifiable-[0-9]*:../../devel/p5-Role-Identifiable
DEPENDS+=	p5-Throwable-[0-9]*:../../devel/p5-Throwable
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

TOOL_DEPENDS+=		p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
#TOOL_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple
# for make test
TOOL_DEPENDS+=		p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
TOOL_DEPENDS+=		p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager


USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Config/MVP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
