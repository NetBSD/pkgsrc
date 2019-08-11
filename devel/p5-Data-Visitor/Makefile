# $NetBSD: Makefile,v 1.26 2019/08/11 13:19:13 wiz Exp $

DISTNAME=	Data-Visitor-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Visitor
COMMENT=	Visitor style traversal of Perl data structures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Load>=0.06:../../devel/p5-Class-Load
DEPENDS+=	p5-Moose>=0.89:../../devel/p5-Moose
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Tie-ToObject>=0.01:../../devel/p5-Tie-ToObject
DEPENDS+=	p5-namespace-clean>=0.19:../../devel/p5-namespace-clean

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=	auto/Data/Visitor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
