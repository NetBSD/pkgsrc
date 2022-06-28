# $NetBSD: Makefile,v 1.3 2022/06/28 11:33:40 wiz Exp $

DISTNAME=	rlib-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GB/GBARR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/rlib
COMMENT=	Perl module to manipulate @INC at compile time with relative paths

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/rlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
