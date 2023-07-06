# $NetBSD: Makefile,v 1.4 2023/07/06 09:40:30 wiz Exp $

DISTNAME=	rlib-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GB/GBARR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/rlib
COMMENT=	Perl module to manipulate @INC at compile time with relative paths

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/rlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
