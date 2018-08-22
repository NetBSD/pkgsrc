# $NetBSD: Makefile,v 1.19 2018/08/22 09:44:44 wiz Exp $
#

DISTNAME=	Test-Compile-v1.3.0
PKGNAME=	p5-${DISTNAME:S/v1/1/}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Compile/
COMMENT=	Perl 5 module to check whether Perl module files compile correctly
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Compile/.packlist

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Devel-CheckOS-[0-9]*:../../devel/p5-Devel-CheckOS
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
