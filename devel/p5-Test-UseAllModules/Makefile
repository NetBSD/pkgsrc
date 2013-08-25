# $NetBSD: Makefile,v 1.7 2013/08/25 05:58:32 wen Exp $

DISTNAME=	Test-UseAllModules-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-UseAllModules/
COMMENT=	Do use_ok() for all the MANIFESTed modules
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/UseAllModules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
