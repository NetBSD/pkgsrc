# $NetBSD: Makefile,v 1.6 2008/07/26 19:11:53 he Exp $
#

DISTNAME=	ExtUtils-MakeMaker-6.44
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MS/MSCHWERN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-MakeMaker/
COMMENT=	Write a Makefile for an extension module from a Makefile.PL

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/ExtUtils/MakeMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
