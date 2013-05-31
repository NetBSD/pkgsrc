# $NetBSD: Makefile,v 1.25 2013/05/31 12:40:18 wiz Exp $

DISTNAME=	ExtUtils-F77-1.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5ext
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-F77/
COMMENT=	Perl module for determining how to link Fortran and C
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		fortran77
PERL5_PACKLIST=		auto/ExtUtils/F77/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
