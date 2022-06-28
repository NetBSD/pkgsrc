# $NetBSD: Makefile,v 1.12 2022/06/28 11:34:31 wiz Exp $

DISTNAME=	Parse-MIME-1.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AR/ARISTOTLE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Parse-MIME
COMMENT=	Parse mime-types, match against media ranges
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Parse/MIME/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
