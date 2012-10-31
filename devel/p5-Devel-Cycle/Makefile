# $NetBSD: Makefile,v 1.15 2012/10/31 11:17:59 asau Exp $

DISTNAME=	Devel-Cycle-1.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Cycle/
COMMENT=	Perl5 module to find memory cycles in objects
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/Cycle/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
