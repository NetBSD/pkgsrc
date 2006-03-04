# $NetBSD: Makefile,v 1.14 2006/03/04 21:29:21 jlam Exp $

DISTNAME=	ExtUtils-F77-1.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ext
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for determining how to link Fortran and C

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/ExtUtils/F77/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
