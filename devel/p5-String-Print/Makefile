# $NetBSD: Makefile,v 1.21 2025/12/31 23:19:52 wen Exp $

DISTNAME=		String-Print-1.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MA/MARKOV/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/String-Print
COMMENT=		Perl 5 module providing a printf alternative
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Unicode-LineBreak-[0-9]*:../../textproc/p5-Unicode-LineBreak
DEPENDS+=		p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/String/Print/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
