# $NetBSD: Makefile,v 1.7 2004/04/27 03:09:58 snj Exp $
#

DISTNAME=		Devel-StackTrace-1.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dst
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/author/DROLSKY/Devel-StackTrace-1.03/
COMMENT=		Perl5 module for stack trace and stack trace frame objects

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/StackTrace/.packlist

DEPENDS+=	p5-Test-Simple>=0.46:../p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
