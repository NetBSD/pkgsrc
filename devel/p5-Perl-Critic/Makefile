# $NetBSD: Makefile,v 1.1.1.1 2007/04/22 21:04:36 seb Exp $
#

DISTNAME=	Perl-Critic-1.051
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Perl-Critic/
COMMENT=	Perl 5 module providing a static Perl source code analysis engine

DEPENDS+=	p5-Config-Tiny>=2:../../devel/p5-Config-Tiny
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Module-Pluggable>=3.1:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-PPI>=1.118:../../devel/p5-PPI
DEPENDS+=	p5-String-Format>=1.13:../../devel/p5-String-Format
DEPENDS+=	p5-B-Keywords>=1.05:../../devel/p5-B-Keywords

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Perl/Critic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
