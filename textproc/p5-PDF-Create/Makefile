# $NetBSD: Makefile,v 1.36 2016/01/15 07:05:00 wen Exp $
#

DISTNAME=	PDF-Create-1.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-Create/
COMMENT=	Perl5 module for creating pdf documents
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/PDF/Create/.packlist

BUILD_DEPENDS=	p5-Test-LeakTrace>=0.14:../../devel/p5-Test-LeakTrace

REPLACE_PERL=	sample.pl sample-cgi.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
