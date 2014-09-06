# $NetBSD: Makefile,v 1.11 2014/09/06 14:53:28 wiz Exp $

DISTNAME=	Test-Requires-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Requires/
COMMENT=	Perl 5 module to test if a module can be loaded
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Requires/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
