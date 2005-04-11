# $NetBSD: Makefile,v 1.11 2005/04/11 21:45:31 tv Exp $

DISTNAME=	ExtUtils-F77-1.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ext
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for determining how to link Fortran and C

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/ExtUtils/F77/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
