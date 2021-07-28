# $NetBSD: Makefile,v 1.1 2021/07/28 07:49:04 wen Exp $

DISTNAME=	PPIx-Utils-0.003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DB/DBOOK/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PPIx-Utils
COMMENT=	Parse Perl string literals and string-literal-like things
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PPI>=1.250:../../devel/p5-PPI
DEPENDS+=	p5-B-Keywords>=1.09:../../devel/p5-B-Keywords

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PPIx/Utils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
