# $NetBSD: Makefile,v 1.16 2016/06/08 19:23:16 wiz Exp $
#

DISTNAME=	MooseX-NonMoose-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-NonMoose/
COMMENT=	Perl 5 module to subclass non-Moose classes with Moose
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/NonMoose/.packlist

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose>=1.08:../../devel/p5-Moose
DEPENDS+=	p5-Try-Tiny>=0:../../devel/p5-Try-Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
