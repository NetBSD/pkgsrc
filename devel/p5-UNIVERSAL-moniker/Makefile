# $NetBSD: Makefile,v 1.31 2026/07/16 19:03:43 wiz Exp $

DISTNAME=	UNIVERSAL-moniker-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	20
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=UNIVERSAL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/UNIVERSAL-moniker
COMMENT=	Perl module for assigning user-friendly names to classes

DEPENDS+=	p5-Lingua-EN-Inflect>=1.88:../../textproc/p5-Lingua-EN-Inflect

PERL5_PACKLIST=	auto/UNIVERSAL/moniker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
