# $NetBSD: Makefile,v 1.6 2002/10/13 22:22:50 seb Exp $

DISTNAME=	ExtUtils-F77-1.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ext
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for determining how to link Fortran and C

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/ExtUtils/F77/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
