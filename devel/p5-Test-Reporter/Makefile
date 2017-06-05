# $NetBSD: Makefile,v 1.16 2017/06/05 14:23:46 ryoon Exp $
#

DISTNAME=	Test-Reporter-1.62
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	3
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
