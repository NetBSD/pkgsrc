# $NetBSD: Makefile,v 1.18 2023/07/06 09:41:42 wiz Exp $

DISTNAME=	PPIx-QuoteLike-0.023
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/W/WY/WYANT/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PPIx-QuoteLike
COMMENT=	Parse Perl string literals and string-literal-like things
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PPI>=1.117:../../devel/p5-PPI
DEPENDS+=	p5-Readonly>=0:../../devel/p5-Readonly

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PPIx/QuoteLike/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
