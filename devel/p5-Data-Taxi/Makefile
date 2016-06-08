# $NetBSD: Makefile,v 1.13 2016/06/08 19:22:47 wiz Exp $

DISTNAME=	Data-Taxi-0.96
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Taxi/
COMMENT=	Perl 5 module providing taint-aware, XML-ish data serialization
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Debug-ShowStuff-[0-9]*:../../devel/p5-Debug-ShowStuff
BUILD_DEPENDS+=	p5-String-Util-[0-9]*:../../devel/p5-String-Util
BUILD_DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Taxi/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
