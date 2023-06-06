# $NetBSD: Makefile,v 1.21 2023/06/06 12:40:46 riastradh Exp $

DISTNAME=	Data-Taxi-0.96
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Taxi
COMMENT=	Perl 5 module providing taint-aware, XML-ish data serialization
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Debug-ShowStuff-[0-9]*:../../devel/p5-Debug-ShowStuff
TOOL_DEPENDS+=	p5-String-Util-[0-9]*:../../devel/p5-String-Util
TOOL_DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Taxi/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
