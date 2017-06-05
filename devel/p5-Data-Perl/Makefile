# $NetBSD: Makefile,v 1.4 2017/06/05 14:22:48 ryoon Exp $

DISTNAME=	Data-Perl-0.002009
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Perl/
COMMENT=	Base classes wrapping fundamental Perl data types
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-strictures-[0-9]*:../../devel/p5-strictures
DEPENDS+=	p5-Role-Tiny-[0-9]*:../../devel/p5-Role-Tiny
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output

PERL5_PACKLIST=	auto/Data/Perl/.packlist

#USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
