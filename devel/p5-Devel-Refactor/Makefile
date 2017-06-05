# $NetBSD: Makefile,v 1.12 2017/06/05 14:22:53 ryoon Exp $

DISTNAME=	Devel-Refactor-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Refactor/
COMMENT=	Perl 5 extension for refactoring Perl code
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/Refactor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
