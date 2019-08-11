# $NetBSD: Makefile,v 1.17 2019/08/11 13:20:07 wiz Exp $
#

DISTNAME=	Package-Generator-1.106
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Package/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Package-Generator
COMMENT=	Perl 5 module to generate new packages
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Package/Generator/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
