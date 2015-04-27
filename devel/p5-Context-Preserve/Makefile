# $NetBSD: Makefile,v 1.8 2015/04/27 01:50:58 mef Exp $

DISTNAME=	Context-Preserve-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../../authors/id/J/JR/JROCKWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Context-Preserve/
COMMENT=	Perl 5 module to run code after a subroutine call
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Context/Preserve/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
