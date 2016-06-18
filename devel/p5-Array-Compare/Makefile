# $NetBSD: Makefile,v 1.27 2016/06/18 13:46:51 mef Exp $

DISTNAME=	Array-Compare-2.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Array-Compare/
COMMENT=	Perl extension for comparing arrays
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny

# for make test
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo


USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Array/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
