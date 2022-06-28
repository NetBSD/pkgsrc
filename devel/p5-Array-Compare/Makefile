# $NetBSD: Makefile,v 1.40 2022/06/28 11:31:53 wiz Exp $

DISTNAME=	Array-Compare-v3.0.8
PKGNAME=	p5-${DISTNAME:S/v3/3/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Array-Compare
COMMENT=	Perl extension for comparing arrays
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo

# for make test
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Array/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
