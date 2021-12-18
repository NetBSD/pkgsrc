# $NetBSD: Makefile,v 1.1 2021/12/18 15:07:01 prlw1 Exp $

DISTNAME=	Sys-MemInfo-0.99
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SC/SCRESTO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Sys-MemInfo
COMMENT=	Perl 5 module for querying physical memory usage
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Sys/MemInfo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
