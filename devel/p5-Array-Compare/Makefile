# $NetBSD: Makefile,v 1.2 2005/02/24 22:38:42 jlam Exp $
#

DISTNAME=		Array-Compare-1.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Array-Compare/
COMMENT=		Perl extension for comparing arrays

#DEPENDS+=		p5-Sub-Uplevel-[0-9]*:../../devel/p5-Sub-Uplevel

USE_LANGUAGES=		# empty
USE_BUILDLINK3=		yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Array/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
