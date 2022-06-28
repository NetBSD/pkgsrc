# $NetBSD: Makefile,v 1.12 2022/06/28 11:36:02 wiz Exp $

DISTNAME=	Sys-CPU-0.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MZ/MZSANFORD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mzsanford/perl-sys-cpu
COMMENT=	Perl 5 module for getting CPU information
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Sys/CPU/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
