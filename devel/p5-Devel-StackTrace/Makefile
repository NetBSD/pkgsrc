# $NetBSD: Makefile,v 1.15 2006/03/04 21:29:20 jlam Exp $
#

DISTNAME=		Devel-StackTrace-1.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dst
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/author/DROLSKY/Devel-StackTrace/
COMMENT=		Perl5 module for stack trace and stack trace frame objects

PERL5_PACKLIST=		auto/Devel/StackTrace/.packlist

DEPENDS+=	p5-Test-Simple>=0.46:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
