# $NetBSD: Makefile,v 1.6 2012/10/31 11:19:07 asau Exp $
#

DISTNAME=	Test-MockModule-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-MockModule/
COMMENT=	Perl 5 module to override subroutines in a module for unit testing

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/MockModule/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
