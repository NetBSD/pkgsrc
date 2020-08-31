# $NetBSD: Makefile,v 1.2 2020/08/31 18:08:53 wiz Exp $

DISTNAME=	Sub-HandlesVia-0.013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/T/TO/TOBYINK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/T/TO/TOBYINK/
COMMENT=	Alternative handles_via implementation
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-MooX-TypeTiny-[0-9]*:../../devel/p5-MooX-TypeTiny
TEST_DEPENDS+=	p5-Mouse-[0-9]*:../../devel/p5-Mouse
TEST_DEPENDS+=	p5-MooseX-ArrayRef-[0-9]*:../../devel/p5-MooseX-ArrayRef
TEST_DEPENDS+=	p5-MooseX-InsideOut-[0-9]*:../../devel/p5-MooseX-InsideOut

PERL5_PACKLIST=	auto/Sub/HandlesVia/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
