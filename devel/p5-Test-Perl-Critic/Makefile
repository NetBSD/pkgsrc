# $NetBSD: Makefile,v 1.14 2016/06/08 19:23:40 wiz Exp $
#

DISTNAME=	Test-Perl-Critic-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Perl-Critic/
COMMENT=	Perl 5 module providing a Perl::Critic interface for test programs
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Perl-Critic>=1.105:../../devel/p5-Perl-Critic

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Build	
PERL5_PACKLIST=	auto/Test/Perl/Critic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
