# $NetBSD: Makefile,v 1.7 2014/05/29 23:36:21 wiz Exp $
#

DISTNAME=	Test-Expect-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Expect/
COMMENT=	Automated driving and testing of terminal-based programs with Perl 5

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Expect/.packlist

DEPENDS+=	p5-Class-Accessor-Chained-[0-9]*:../../devel/p5-Class-Accessor-Chained
DEPENDS+=	p5-Expect-Simple-[0-9]*:../../devel/p5-Expect-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
