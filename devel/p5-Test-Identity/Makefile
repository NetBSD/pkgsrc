# $NetBSD: Makefile,v 1.10 2019/08/11 13:20:31 wiz Exp $

DISTNAME=	Test-Identity-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Identity
COMMENT=	Assert the referential identity of a reference
LICENSE=	${PERL5_LICENSE}


#BUILD_DEPENDS+=	{perl>=5.11.3,p5-Module-Build>=0.36}:../../devel/p5-Module-Build

USE_LANGUAGES=	
PERL5_MODULE_TYPE+=	Module::Build
PERL5_PACKLIST+=	auto/Test/Identity/.packlist
PERL5_REQD+=	5.7.3	# Scalar::Util >= 0
PERL5_REQD+=	5.6.2	# Test::More >= 0
PERL5_REQD+=	5.8.8	# Test::Builder::Tester >= 0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
