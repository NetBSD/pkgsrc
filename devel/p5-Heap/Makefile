# $NetBSD: Makefile,v 1.2 2002/10/13 22:22:48 seb Exp $

DISTNAME=	Heap-0.50
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Heap/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl collection of routines for managing a heap data structure

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Heap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
