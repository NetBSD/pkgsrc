# $NetBSD: Makefile,v 1.24 2019/08/11 13:19:15 wiz Exp $

DISTNAME=	Devel-Cycle-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Cycle
COMMENT=	Perl5 module to find memory cycles in objects
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/Cycle/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
