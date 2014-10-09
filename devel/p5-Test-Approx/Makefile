# $NetBSD: Makefile,v 1.7 2014/10/09 14:06:28 wiz Exp $
#

DISTNAME=	Test-Approx-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Approx
COMMENT=	Perl module for testing approximate equality of values
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-LevenshteinXS>=0.03:../../textproc/p5-Text-LevenshteinXS

PERL5_PACKLIST=		auto/Test/Approx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
