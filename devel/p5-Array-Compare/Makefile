# $NetBSD: Makefile,v 1.1.1.1 2005/02/22 00:33:36 wiz Exp $
#

DISTNAME=		Array-Compare-1.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Array-Compare/
COMMENT=		Perl extension for comparing arrays

#DEPENDS+=		p5-Sub-Uplevel-[0-9]*:../../devel/p5-Sub-Uplevel

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_USES_MODULE_BUILD=	YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
