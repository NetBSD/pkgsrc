# $NetBSD: Makefile,v 1.38 2023/07/06 09:40:29 wiz Exp $

DISTNAME=	local-lib-2.000028
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HAARG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/local-lib
COMMENT=	Create and use a local lib/ for perl modules with PERL5LIB
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/local/lib/.packlist

MAKE_ENV+=	PERL5_CPANM_IS_RUNNING=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
