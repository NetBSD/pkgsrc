# $NetBSD: Makefile,v 1.23 2019/08/11 13:20:29 wiz Exp $

DISTNAME=	Test-Compile-v2.2.2
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Compile
COMMENT=	Perl 5 module to check whether Perl module files compile correctly
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Compile/.packlist

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Devel-CheckOS-[0-9]*:../../devel/p5-Devel-CheckOS
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
