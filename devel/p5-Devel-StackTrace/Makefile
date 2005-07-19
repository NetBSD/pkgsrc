# $NetBSD: Makefile,v 1.12 2005/07/19 10:20:07 grant Exp $
#

DISTNAME=		Devel-StackTrace-1.11
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dst
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/author/DROLSKY/Devel-StackTrace/
COMMENT=		Perl5 module for stack trace and stack trace frame objects

PERL5_PACKLIST=		auto/Devel/StackTrace/.packlist

DEPENDS+=	p5-Test-Simple>=0.46:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
