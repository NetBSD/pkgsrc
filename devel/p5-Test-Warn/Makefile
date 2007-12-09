# $NetBSD: Makefile,v 1.7 2007/12/09 00:22:40 hiramatsu Exp $
#

DISTNAME=		Test-Warn-0.10
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Warn/
COMMENT=		Perl extension to test methods for warnings

DEPENDS+=		p5-Array-Compare-[0-9]*:../../devel/p5-Array-Compare
DEPENDS+=		p5-Sub-Uplevel-[0-9]*:../../devel/p5-Sub-Uplevel
DEPENDS+=		p5-Tree-DAG_Node-[0-9]*:../../devel/p5-Tree-DAG_Node

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Warn/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
