# $NetBSD: Makefile,v 1.23 2024/05/05 07:18:06 wiz Exp $

DISTNAME=	CPAN-Meta-Requirements-2.143
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}
#${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/} \
#		https://cpan.metacpan.org/authors/id/R/RJ/RJBS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/CPAN-Meta-Requirements
COMMENT=	Set of version requirements for a CPAN dist
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-ExtUtils-Config-[0-9]*:../../devel/p5-ExtUtils-Config

USE_LANGUAGES=		# none
PERL5_PACKLIST=		auto/CPAN/Meta/Requirements/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
