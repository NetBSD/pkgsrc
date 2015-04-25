# $NetBSD: Makefile,v 1.19 2015/04/25 01:27:53 mef Exp $

DISTNAME=	Config-Any-0.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Any/
COMMENT=	Perl extension for handling config files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Pluggable>=3.01:../../devel/p5-Module-Pluggable

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Config/Any/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
