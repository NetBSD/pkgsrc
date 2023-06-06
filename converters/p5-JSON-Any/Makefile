# $NetBSD: Makefile,v 1.36 2023/06/06 12:40:24 riastradh Exp $

DISTNAME=	JSON-Any-1.39
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/JSON-Any
COMMENT=	Wrapper Class for the various JSON classes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/JSON/Any/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

# p5-JSON-XS appears to be the current "best of breed"
# and is the preferred JSON dependency (see Makefile.PL)
DEPENDS+=	p5-JSON-XS>=2.232:../../converters/p5-JSON-XS
# for make test
TOOL_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TOOL_DEPENDS+=	p5-Test-Without-Module-[0-9]*:../../devel/p5-Test-Without-Module
TOOL_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
TOOL_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
