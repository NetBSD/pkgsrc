# $NetBSD: Makefile,v 1.1.1.1 2007/05/13 20:42:10 seb Exp $
#

DISTNAME=	Class-Std-v0.0.8
PKGNAME=	p5-Class-Std-0.0.8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Std/
COMMENT=	Perl 5 module to support creation of standard inside-out classes

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Class/Std/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
