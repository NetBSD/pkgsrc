# $NetBSD: Makefile,v 1.1.1.1 2005/02/22 00:33:36 wiz Exp $
#

DISTNAME=		Test-Memory-Cycle-1.00
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Memory-Cycle/
COMMENT=		Check for memory leaks and circular memory references

DEPENDS+=		p5-Devel-Cycle-[0-9]*:../../devel/p5-Devel-Cycle

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Memory/Cycle/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
