# $NetBSD: Makefile,v 1.2 2014/05/29 23:36:17 wiz Exp $
#

DISTNAME=		String-Print-0.13
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
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
