# $NetBSD: Makefile,v 1.11 2022/06/28 11:36:38 wiz Exp $

DISTNAME=	Unicode-CaseFold-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Unicode-CaseFold
COMMENT=	Unicode case-folding for case-insensitive lookups
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Unicode/CaseFold/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
