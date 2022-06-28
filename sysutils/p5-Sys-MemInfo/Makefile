# $NetBSD: Makefile,v 1.2 2022/06/28 11:36:03 wiz Exp $

DISTNAME=	Sys-MemInfo-0.99
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SC/SCRESTO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Sys-MemInfo
COMMENT=	Perl 5 module for querying physical memory usage
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Sys/MemInfo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
