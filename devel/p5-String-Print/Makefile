# $NetBSD: Makefile,v 1.6 2017/06/05 14:23:36 ryoon Exp $
#

DISTNAME=		String-Print-0.15
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
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
