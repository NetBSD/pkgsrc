# $NetBSD: Makefile,v 1.25 2021/07/06 08:02:41 wen Exp $

DISTNAME=	String-Random-0.31
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/String-Random
COMMENT=	Perl module to generate random strings based on a pattern
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=	auto/String/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
