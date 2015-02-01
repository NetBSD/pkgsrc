# $NetBSD: Makefile,v 1.12 2015/02/01 05:49:55 mef Exp $
#

DISTNAME=	Test-Reporter-1.60
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Base/
COMMENT=	Perl module which sends test results to cpan-testers@perl.org
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Reporter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
