# $NetBSD: Makefile,v 1.3 2005/07/13 18:01:29 jlam Exp $
#

DISTNAME=		Test-Warn-0.08
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Warn/
COMMENT=		Perl extension to test methods for warnings

DEPENDS+=		p5-Array-Compare-[0-9]*:../../devel/p5-Array-Compare
DEPENDS+=		p5-Tree-DAG_Node-[0-9]*:../../devel/p5-Tree-DAG_Node

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Warn/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
