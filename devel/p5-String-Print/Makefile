# $NetBSD: Makefile,v 1.8 2017/07/09 14:47:12 wen Exp $
#

DISTNAME=		String-Print-0.92
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/String-Print/
COMMENT=		Perl 5 module providing a printf alternative
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Unicode-LineBreak>=0:../../textproc/p5-Unicode-LineBreak

PERL5_PACKLIST=		auto/String/Print/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
