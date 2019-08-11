# $NetBSD: Makefile,v 1.22 2019/08/11 13:22:55 wiz Exp $
#

DISTNAME=		Data-SimplePassword-0.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Data-SimplePassword
COMMENT=		Simple random password generator
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-CLASS-[0-9]*:../../devel/p5-CLASS
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Crypt-Random-[0-9]*:../../security/p5-Crypt-Random
DEPENDS+=	p5-Math-Random-MT-Perl-[0-9]*:../../math/p5-Math-Random-MT-Perl
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

# recommended
DEPENDS+=	p5-Math-Random-MT-[0-9]*:../../math/p5-Math-Random-MT

# for make test
BUILD_DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
BUILD_DEPENDS+=	p5-Moo>=1.001:../../devel/p5-Moo
BUILD_DEPENDS+=	p5-MooX-ClassAttribute-[0-9]*:../../devel/p5-MooX-ClassAttribute
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

REPLACE_PERL+=	script/rndpassword

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/SimplePassword/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
