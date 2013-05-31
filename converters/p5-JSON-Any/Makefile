# $NetBSD: Makefile,v 1.18 2013/05/31 12:39:44 wiz Exp $

DISTNAME=	JSON-Any-1.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5 converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=JSON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-Any/
COMMENT=	Wrapper Class for the various JSON classes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/JSON/Any/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

# p5-JSON-XS appears to be the current "best of breed"
# and is the preferred JSON dependency (see Makefile.PL)
DEPENDS+=		p5-JSON-XS>=2.232:../../converters/p5-JSON-XS

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
