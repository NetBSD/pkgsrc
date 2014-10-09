# $NetBSD: Makefile,v 1.2 2014/10/09 14:06:21 wiz Exp $
#

DISTNAME=	Inline-C-0.61
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Inline/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Inline-C/
COMMENT=	Write Perl Subroutines in C
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Inline>=0.58:../../devel/p5-Inline
DEPENDS+=	p5-Parse-RecDescent>=1.80:../../devel/p5-Parse-RecDescent

MAKE_ENV+=	PERL_MM_USE_DEFAULT=1

PERL5_PACKLIST=		auto/Inline/C/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
