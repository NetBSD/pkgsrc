# $NetBSD: Makefile,v 1.22 2023/07/06 09:39:15 wiz Exp $

DISTNAME=	Getopt-ArgvFile-1.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Getopt-ArgvFile
COMMENT=	Interpolates script options from files into @ARGV or another array
LICENSE=	artistic

PERL5_PACKLIST=		auto/Getopt/ArgvFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
