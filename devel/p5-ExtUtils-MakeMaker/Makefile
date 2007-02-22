# $NetBSD: Makefile,v 1.4 2007/02/22 19:26:23 wiz Exp $
#

DISTNAME=	ExtUtils-MakeMaker-6.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MS/MSCHWERN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Write a Makefile for an extension module from a Makefile.PL

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/ExtUtils/MakeMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
