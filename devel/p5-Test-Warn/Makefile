# $NetBSD: Makefile,v 1.10 2008/10/19 19:18:02 he Exp $
#

DISTNAME=		Test-Warn-0.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Warn/
COMMENT=		Perl extension to test methods for warnings

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Array-Compare-[0-9]*:../../devel/p5-Array-Compare
DEPENDS+=		p5-Sub-Uplevel-[0-9]*:../../devel/p5-Sub-Uplevel
DEPENDS+=		p5-Tree-DAG_Node-[0-9]*:../../devel/p5-Tree-DAG_Node

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Warn/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
