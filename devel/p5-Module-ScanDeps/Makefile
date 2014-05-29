# $NetBSD: Makefile,v 1.32 2014/05/29 23:36:05 wiz Exp $
#

DISTNAME=	Module-ScanDeps-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5msd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-ScanDeps/
COMMENT=	Perl 5 module to recursively scan Perl code for dependencies
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/ScanDeps/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

REPLACE_PERL+=	script/scandeps.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
