# $NetBSD: Makefile,v 1.36 2025/11/15 03:33:32 wen Exp $

DISTNAME=	Test-Unit-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://cpan.uwinnipeg.ca/dist/Test-Unit
COMMENT=	Perl extension module for Unit Tests

DEPENDS+=	p5-Class-Inner-[0-9]*:../../devel/p5-Class-Inner
DEPENDS+=	p5-Devel-Symdump-[0-9]*:../../devel/p5-Devel-Symdump
DEPENDS+=	p5-Error-[0-9]*:../../devel/p5-Error

PERL5_PACKLIST=		auto/Test/Unit/.packlist

REPLACE_PERL+=	*.pl

EXTRACT_USING=	gtar

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
