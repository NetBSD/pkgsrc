# $NetBSD: Makefile,v 1.37 2016/02/03 13:14:43 mef Exp $
#

DISTNAME=	PDF-Create-1.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-Create/
COMMENT=	Perl5 module for creating pdf documents
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/PDF/Create/.packlist

BUILD_DEPENDS=	p5-Test-LeakTrace>=0.14:../../devel/p5-Test-LeakTrace
#UILD_DEPENDS+=	p5-Test-CPAN-Changes-[0-9]*:../../devel/p5-Test-CPAN-Changes
BUILD_DEPENDS+=	p5-Test-CheckManifest>=0.9:../../devel/p5-Test-CheckManifest
#UILD_DEPENDS+=	p5-Test-CPAN-Meta-JSON-[0-9]*:../../devel/p5-Test-CPAN-Meta-JSON


REPLACE_PERL=	sample.pl sample-cgi.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
