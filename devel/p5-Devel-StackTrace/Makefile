# $NetBSD: Makefile,v 1.16 2006/07/19 22:37:21 wiz Exp $
#

DISTNAME=		Devel-StackTrace-1.13
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
