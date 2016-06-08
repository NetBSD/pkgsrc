# $NetBSD: Makefile,v 1.8 2016/06/08 19:23:16 wiz Exp $
#

DISTNAME=	MooseX-MarkAsMethods-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-MarkAsMethods/
COMMENT=	Mark overload code symbols as methods
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/MarkAsMethods/.packlist

DEPENDS+=	p5-Moose>=1.10:../../devel/p5-Moose
DEPENDS+=	p5-B-Hooks-EndOfScope-[0-9]*:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-namespace-autoclean>=0.12:../../devel/p5-namespace-autoclean

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
